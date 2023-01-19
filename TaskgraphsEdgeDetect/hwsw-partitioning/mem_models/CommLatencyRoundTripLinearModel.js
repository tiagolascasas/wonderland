"use strict";

    class CommLatencyRoundTripLinearModel {
        static #m = 0.0021284729450900134;
        static #b = -24.066112516681187;

        static predict(x) {
            return x * this.#m + this.#b;
        }

        static toString() {
            return "y = x * " + this.#m + " + " + this.#b;
        }
    }
    