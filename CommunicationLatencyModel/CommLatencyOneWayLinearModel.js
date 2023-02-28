"use strict";

    class CommLatencyOneWayLinearModel {
        static #m = 0.0023216419041647922;
        static #b = 83.36910879635161;

        static predict(x) {
            return x * this.#m + this.#b;
        }

        static toString() {
            return "y = x * " + this.#m + " + " + this.#b;
        }
    }
    