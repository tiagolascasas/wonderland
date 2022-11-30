import io
import sys
import numpy as np
from PIL import Image


def imgToBytes(fname):
    with open(fname, "rb") as image:
        f = image.read()
        b = bytearray(f)
        b = b[54:]

        idx = []
        i = 0
        while i < 32 * 3 - 2:
            idx.append(i + 2)
            idx.append(i + 1)
            idx.append(i)
            i += 3

        newlist = []
        for i in range(32):
            for j in reversed(idx):
                newlist.append(b[i * 32 * 3 + j])
        newlist.reverse()

        return list(newlist)


def bytesToC(arr):
    s = ",".join(map(str, arr))
    f = open("img.h", "w+")
    f.write(s)
    f.close()


def bytesToImg(img):
    file = open(img, mode='r')
    all = file.read()
    file.close()

    split = all.split(",")
    intarr = list(map(int, split))

    bytearr = np.array(intarr, dtype=np.uint8)
    im = Image.fromarray(bytearr.reshape(32, 32, 3))
    im.save("imgconverted.bmp")


def main():
    if len(sys.argv) != 3:
        print("error")
        return

    if sys.argv[1] == "-b":
        arr = imgToBytes(sys.argv[2])
        bytesToC(arr)

    if sys.argv[1] == "-i":
        bytesToImg(sys.argv[2])


main()
