import numpy as np
import csv
from io import StringIO
from sklearn.linear_model import LinearRegression
import matplotlib.pyplot as plt


def main():
    model_name = "CommLatency"

    csv1 = "Int_Roundtrip.csv"
    m1, b1, x1, y1 = linreg(csv1)
    modelToJS(m1, b1, model_name + "RoundTrip")

    csv2 = "Int_Oneway.csv"
    m2, b2, x2, y2 = linreg(csv2)
    modelToJS(m2, b2, model_name + "OneWay")

    plt.scatter(x1, y1, color="black")
    x1_line = np.linspace(0, 5000000, 5000000)
    y1_line = m1 * x1_line + b1
    plt.plot(x1_line, y1_line, color="red", label="CPU -> FPGA -> CPU")

    plt.scatter(x2, y2, color="grey")
    x2_line = np.linspace(0, 5000000, 5000000)
    y2_line = m2 * x2_line + b2
    plt.plot(x2_line, y2_line, color="blue", label="CPU -> FPGA")

    plt.legend(loc='upper left')
    plt.xlabel("Number of words (4 bytes) communicated to kernel")
    plt.ylabel("Communication time (us)")
    plt.ticklabel_format(style='plain')
    plt.savefig('comm_model.pdf')


def linreg(csv_name):
    x_raw = []
    y_raw = []

    with open(csv_name, newline='') as csvfile:
        reader = csv.reader(csvfile, delimiter=",")
        for row in reader:
            x_raw.append(int(row[0]))
            y_raw.append(int(row[1]))

    x = np.array(x_raw).reshape((-1, 1))
    y = np.array(y_raw)

    model = LinearRegression()
    model.fit(x, y)

    r_sq = model.score(x, y)
    b = model.intercept_
    m = model.coef_[0]
    print(f"R^2: {r_sq}")
    print(
        f"Adjusted R^2: {1 - (1-model.score(x, y))*(len(y)-1)/(len(y)-x.shape[1]-1)}")
    print(f"intercept: {b}")
    print(f"slope: {m}")
    return m, b, x_raw, y_raw

# for i in range(0, len(x)):
#    print(f"{x[i][0]} -> {int(x[i][0] * m + b)} (actual: {y[i]})")


def modelToJS(m, b, model_name):
    js = f'''"use strict";

    class {model_name}LinearModel {{
        static #m = {m};
        static #b = {b};

        static predict(x) {{
            return x * this.#m + this.#b;
        }}

        static toString() {{
            return "y = x * " + this.#m + " + " + this.#b;
        }}
    }}
    '''
    with open(f"{model_name}LinearModel.js", "w") as file:
        file.write(js)


main()
