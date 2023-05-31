"use strict";

laraImport("lara.util.IdGenerator");

class Voidifier {
    constructor() { }

    voidify(fun, returnVarName = "rtr_value") {
        const returnStmts = this.#findNonvoidReturnStmts(fun);
        if (returnStmts.length == 0) {
            return false;
        }

        this.#voidifyFunction(fun, returnStmts, returnVarName);

        for (const call of Query.search("call", { "signature": fun.signature })) {
            this.#handleCall(call, fun);
        }
        return true;
    }


    #handleCall(call, fun) {
        const parent = call.parent;
        let newVarref = null;
        let replaceParent = true;

        if (parent.instanceOf("binaryOp")) {
            newVarref = ClavaJoinPoints.varRef(parent.left.declaration);
        }
        else if (parent.instanceOf("exprStmt")) {
            const tempId = IdGenerator.next("__tmp");
            const tempType = fun.params[fun.params.length - 1].type;
            const tempVar = ClavaJoinPoints.varDeclNoInit(tempId, tempType);
            call.insertBefore(tempVar);
            newVarref = ClavaJoinPoints.varRef(tempVar);
        }
        else {
            throw new Error("[Voidifier] Unexpected parent of call: " + parent.joinPointType);
        }

        const op = ClavaJoinPoints.unaryOp("&", newVarref);
        const args = [...call.argList, op];
        const newCall = ClavaJoinPoints.call(fun, args);

        if (replaceParent) {
            parent.replaceWith(newCall);
        }
        else {
            call.replaceWith(newCall);
        }
    }

    #voidifyFunction(fun, returnStmts, returnVarName) {
        const retType = returnStmts[0].children[0].type;
        const pointerType = ClavaJoinPoints.pointer(retType);
        const retParam = ClavaJoinPoints.param(returnVarName, pointerType);
        fun.addParam(retParam);

        for (const ret of returnStmts) {
            const derefRet = ClavaJoinPoints.unaryOp("*", retParam.varref());
            const retVal = ret.children[0];
            retVal.detach();
            const op = ClavaJoinPoints.binaryOp("=", derefRet, retVal, retType);
            ret.insertBefore(ClavaJoinPoints.exprStmt(op));

        }
        fun.setType(ClavaType.asType("void"));
    }

    #findNonvoidReturnStmts(fun) {
        const returnStmts = [];
        for (const ret of Query.searchFrom(fun, "returnStmt")) {
            if (ret.numChildren > 0) {
                returnStmts.push(ret);
            }
        }
        return returnStmts;
    }
}