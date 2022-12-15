"use strict";

class CommLatencyLinearModel {
    static #m = 0.01192945308050173;
    static #b = 996.2512680716209;

    static predict(x) {
        return x * this.#m + this.#b;
    }

    static toString() {
        return "y = x * " + this.#m + " + " + this.#b;
    }
}
