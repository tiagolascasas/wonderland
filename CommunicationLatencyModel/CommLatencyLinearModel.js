"use strict";

class CommLatencyLinearModel {
    static #m = 0.003060551395005729;
    static #b = 88.92241402613217;

    static predict(x) {
        return x * this.#m + this.#b;
    }

    static toString() {
        return "y = x * " + this.#m + " + " + this.#b;
    }
}
