"use strict";

    class CommLatencyOneWayLinearModel {
        static #m = 0.001458285258474522;
        static #b = -25.202226131691077;

        static predict(x) {
            return x * this.#m + this.#b;
        }

        static toString() {
            return "y = x * " + this.#m + " + " + this.#b;
        }
    }
    