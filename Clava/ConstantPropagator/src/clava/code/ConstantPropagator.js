"use strict";

laraImport("weaver.Query");
laraImport("clava.ClavaJoinPoints");


class ConstantPropagator {

    constructor() { }

    propagate(func) {
        let passes = 1;
        let hasChanged = this.#doPass(func);

        while (hasChanged) {
            hasChanged = this.#doPass(func);
            passes++;
        }
        return passes;
    }

    #doPass(func) {
        let hasChanged = false;

        for (const op of Query.search("binaryOp")) {
            const isLiteral1 = op.left.instanceOf(["intLiteral", "floatLiteral"]);
            const isLiteral2 = op.right.instanceOf(["intLiteral", "floatLiteral"]);

            if (isLiteral1 && isLiteral2) {
                hasChanged = this.#fold(op);
            }
        }

        return hasChanged;
    }

    #convertToNumber(literal) {
        if (literal.instanceOf("intLiteral")) {
            return parseInt(literal.value);
        }
        else if (literal.instanceOf("floatLiteral")) {
            return parseFloat(literal.value);
        }
        else {
            throw new Error("Unknown literal type");
        }
    }

    #fold(op) {
        const n1 = this.#convertToNumber(op.left);
        const n2 = this.#convertToNumber(op.right);

        let newLit = null;
        if (op.left.instanceOf("floatLiteral") || op.right.instanceOf("floatLiteral")) {
            newLit = this.#doOperation(op.kind, n1, n2, true);
        }
        else {
            newLit = this.#doOperation(op.kind, n1, n2, false);
        }

        if (newLit == null) {
            return false;
        }
        else {
            op.replaceWith(newLit);
            return true;
        }
    }

    #buildLiteral(res, isFloat) {
        if (isNaN(res)) {
            return null;
        }
        if (isFloat) {
            const n = parseFloat(res);
            if (!isNaN(n)) {
                return ClavaJoinPoints.doubleLiteral(n);
            }
        }
        else {
            const n = parseInt(res);
            if (!isNaN(n)) {
                return ClavaJoinPoints.integerLiteral(n);
            }
        }
        return null;
    }

    #doOperation(kind, n1, n2, isFloat) {
        let res = null;

        switch (kind) {
            case "mul":
                res = n1 * n2;
                break;
            case "div":
                res = n1 / n2;
                break;
            case "rem":
                res = n1 % n2;
                break;
            case "add":
                res = n1 + n2;
                break;
            case "sub":
                res = n1 - n2;
                break;
            case "shl": 
                res = n1 << n2;
                break; 
            case "shr":
                res = n1 >> n2; 
                break; 
            case "cmp": 
                // no idea
                break; 
            case "lt": 
                res = n1 < n2;
                res = Number(res);
                break; 
            case "gt": 
                res = n1 > n2;
                res = Number(res);
                break; 
            case "le": 
                res = n1 <= n2;
                res = Number(res);
                break; 
            case "ge":
                res = n1 >= n2; 
                res = Number(res);
                break; 
            case "eq": 
                res = n1 == n2;
                res = Number(res);
                break; 
            case "ne": 
                res = n1 != n2;
                res = Number(res);
                break; 
            case "and": 
                res = n1 & n2;
                break; 
            case "xor": 
                res = n1 ^ n2;
                break; 
            case "or": 
                res = n1 | n2;
                break; 
            case "l_and":
                res = n1 && n2;
                res = Number(res);
                break;
            case "l_or":
                res = n1 || n2;
                res = Number(res);
                break;
            default:
                break;
        }
        if (res != null) {
            return this.#buildLiteral(res, isFloat);
        }
        else {
            return null;
        }
    }
}