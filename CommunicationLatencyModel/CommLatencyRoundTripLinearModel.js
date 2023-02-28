"use strict";

    class CommLatencyRoundTripLinearModel {
        static #m = 0.003057786375093787;
        static #b = 91.05335034226118;

        static predict(x) {
            return x * this.#m + this.#b;
        }

        static toString() {
            return "y = x * " + this.#m + " + " + this.#b;
        }
    }
    