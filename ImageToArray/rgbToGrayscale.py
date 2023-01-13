import numpy as np
from PIL import Image


fname = "img_2560_1440.dat"

file = open(fname, mode='r')
all = file.read()
file.close()

split = all.split(",")
gray = []

i = 0
while i < len(split):
    r = int(split[i])
    g = int(split[i+1])
    b = int(split[i+2])
    color = 0.299 * r + 0.587 * g + 0.114 * b
    gray.append(str(int(color)))
    i += 3

s = ','.join(gray)
f = open("img_2560_1440_gray.dat", "w+")
f.write(s)
f.close()
