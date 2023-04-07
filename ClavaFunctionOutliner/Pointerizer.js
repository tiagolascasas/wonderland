"use strict";

laraImport("clava.ClavaJoinPoints");

class Pointerizer {
    static scalarRefToDereferencedPointer(varref) {
        if (varref.type.joinPointType != "builtinType") {
            println("You cannot turn a non-scalar varref into a dereferenced pointer");
            return null;
        }
        // needs to change to programatically create a pointerType
        const pointerType = "int*";
        const newType = ClavaType.asType(pointerType);
        // ------------------------------------------------------
        varref.setType(newType);
        const op = ClavaJoinPoints.unaryOp("deref", varref);
        println("HERE 1");
        varref.replaceWith(op);
        println("HERE 2");
    }
}