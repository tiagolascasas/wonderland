import numpy as np
import csv
from io import StringIO
from sklearn.linear_model import LinearRegression

# Params
model_name = "CommLatency"
csv_name = "res.csv"

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

for i in range(0, len(x)):
    print(f"{x[i][0]} -> {int(x[i][0] * m + b)} (actual: {y[i]})")

print("")

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
