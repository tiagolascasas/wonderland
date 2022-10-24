"use strict";

class Tool {
    constructor(disableWeaving) {
        if (this.constructor == Tool) {
            throw new Error("Class 'Tool' is abstract and cannot be instantiated");
        }

        this.disableWeaving = defaultValue(disableWeaving, false);
    }
}