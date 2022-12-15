import numpy as np
import csv
from io import StringIO
from sklearn.linear_model import LinearRegression

# Params
normalize = True
model_name = "CommLatency"
raw = '''0,450
1000,511
100000,1848
500000,6987
750000,10293
1000000,14607
2000000,28562
3000000,38297
4000000,48271
5000000,59695
'''
x_raw = []
y_raw = []

f = StringIO(raw)
reader = csv.reader(f, delimiter=',')
for row in reader:
    x_raw.append(int(row[0]))
    y_raw.append(int(row[1]))

x = np.array(x_raw).reshape((-1, 1))
y = np.array(y_raw)

if normalize:
    # remove kernel exec time from all values,
    # i.e. 0 words take 0 seconds to communicate
    y = y - y[0]

model = LinearRegression()
model.fit(x, y)

r_sq = model.score(x, y)
b = model.intercept_
m = model.coef_[0]
print(f"coefficient of determination: {r_sq}")
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
