import sys
import csv
import re

file = sys.argv[1]
print(file)

entries = {}

with open(file) as csv_file:
    csv_reader = csv.reader(csv_file, delimiter=",")
    for row in csv_reader:
        if len(row) == 2 and "us" in row[1] and row[1] != "us":
            fun = row[0]
            time = int(re.sub("[^0-9.\-]", "", row[1]))

            if fun not in entries:
                entries[fun] = [time]
            else:
                entries[fun].append(time)

for key in entries:
    entries[key] = int(sum(entries[key]) / len(entries[key]))

for key in entries:
    print(key + "," + str(entries[key]))
