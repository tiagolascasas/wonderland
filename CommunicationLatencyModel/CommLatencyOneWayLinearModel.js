"use strict";

    class CommLatencyOneWayLinearModel {
        static #m = 0.0023236828181779426;
        static #b = 81.79622399724622;

        static predict(x) {
            return x * this.#m + this.#b;
        }

        static toString() {
            return "y = x * " + this.#m + " + " + this.#b;
        }
    }
    