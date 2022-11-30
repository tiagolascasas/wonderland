import os
import sys
import numpy as np
from PIL import Image


def imgToBytes(fname, height, width):
    size = height * width

    with open(fname, "rb") as image:
        f = image.read()
        b = bytearray(f)
        b = b[54:]

        idx = []
        i = 0
        while i < width * 3 - 2:
            idx.append(i + 2)
            idx.append(i + 1)
            idx.append(i)
            i += 3

        newlist = []
        for i in range(height):
            for j in reversed(idx):
                newlist.append(b[i * width * 3 + j])
        newlist.reverse()

        return list(newlist)


def bytesToC(arr, name, height, width):
    s = ",".join(map(str, arr))
    f = open(name + "_" + str(height) + "_" + str(width) + ".h", "w+")
    f.write(s)
    f.close()


def cToBytes(img, height, width):
    name = img.split(".")[0]
    file = open(img, mode='r')
    all = file.read()
    file.close()

    split = all.split(",")
    intarr = list(map(int, split))

    bytearr = np.array(intarr, dtype=np.uint8)
    return bytearr


def bytesToImg(arr, name, height, width, color):
    if color == "g":
        im = Image.fromarray(arr.reshape(height, width))
    else:
        im = Image.fromarray(arr.reshape(height, width, 3))
    im.save(name + "_converted.bmp")


def main():
    if len(sys.argv) != 6:
        print("error")
        return

    mode = sys.argv[1]
    img = sys.argv[2]
    height = int(sys.argv[3])
    width = int(sys.argv[4])
    color = sys.argv[5]
    name = os.path.basename(img).split(".")[0]

    if mode == "-b":
        arr = imgToBytes(img, height, width)
        bytesToC(arr, name, height, width)

    if mode == "-i":
        arr = cToBytes(img, height, width)
        bytesToImg(arr, name, height, width, color)


main()
