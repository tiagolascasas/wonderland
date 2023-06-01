"use strict";

laraImport("lara.util.IdGenerator");

class Voidifier {
    constructor() { }

    voidify(fun, returnVarName = "rtr_value") {
        const returnStmts = this.#findNonvoidReturnStmts(fun);
        if (returnStmts.length == 0) {
            return false;
        }
        const retVarType = fun.returnType;

        this.#voidifyFunction(fun, returnStmts, returnVarName, retVarType);

        for (const call of Query.search("call", { "signature": fun.signature })) {
            this.#handleCall(call, fun, retVarType);
        }
        return true;
    }


    #handleCall(call, fun, retVarType) {
        const parent = call.parent;
        let newArg = null;
        let replaceParent = true;

        if (parent.instanceOf("binaryOp")) {
            if (parent.left.instanceOf("varref")) {
                const newRef = ClavaJoinPoints.varRef(parent.left.declaration);
                newArg = ClavaJoinPoints.unaryOp("&", newRef);
            }
            else if (parent.left.instanceOf("arrayAccess")) {
                //newArg = parent.left;
                newArg = ClavaJoinPoints.unaryOp("&", parent.left);
                replaceParent = true;
                //parent.removeChildren();
                //newArg.detach();
            }
            else {
                throw new Error("[Voidifier] Unexpected lhs of call: " + parent.left.joinPointType + "\nOn source code line: " + parent.parent.code);
            }
        }
        else if (parent.instanceOf("exprStmt")) {
            const tempId = IdGenerator.next("__dummmy");
            const tempVar = ClavaJoinPoints.varDeclNoInit(tempId, retVarType);
            call.insertBefore(tempVar);
            const newRef = ClavaJoinPoints.varRef(tempVar);
            newArg = ClavaJoinPoints.unaryOp("&", newRef);
        }
        else {
            throw new Error("[Voidifier] Unexpected parent of call: " + parent.joinPointType);
        }

        const args = [...call.argList, newArg];
        const newCall = ClavaJoinPoints.call(fun, args);

        if (replaceParent) {
            parent.replaceWith(newCall);
        }
        else {
            call.replaceWith(newCall);
        }
    }

    #voidifyFunction(fun, returnStmts, returnVarName, retVarType) {
        const pointerType = ClavaJoinPoints.pointer(retVarType);
        const retParam = ClavaJoinPoints.param(returnVarName, pointerType);
        fun.addParam(retParam);

        for (const ret of returnStmts) {
            const derefRet = ClavaJoinPoints.unaryOp("*", retParam.varref());
            const retVal = ret.children[0];
            retVal.detach();
            const op = ClavaJoinPoints.binaryOp("=", derefRet, retVal, retVarType);
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