#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <memory>

#include "util.h"
#include "config.h"

unsigned char *readBMP(const std::string &filename, int width, int height, int bitCount)
{
    std::ifstream file(filename, std::ios::binary);
    if (!file)
    {
        std::cerr << "Error opening file." << std::endl;
        return nullptr;
    }

    BITMAPFILEHEADER fileHeader;
    file.read(reinterpret_cast<char *>(&fileHeader), sizeof(BITMAPFILEHEADER));
    if (fileHeader.bfType != 0x4D42)
    { // 'BM' in little-endian
        std::cerr << "Not a valid BMP file." << std::endl;
        return nullptr;
    }

    BITMAPINFOHEADER infoHeader;
    file.read(reinterpret_cast<char *>(&infoHeader), sizeof(BITMAPINFOHEADER));

    file.seekg(fileHeader.bfOffBits, std::ios::beg);

    width = infoHeader.biWidth;
    height = infoHeader.biHeight;
    bitCount = infoHeader.biBitCount;
    int row_padded = (width * 3 + 3) & (~3);

    unsigned char *pixels = new unsigned char[row_padded * height];

    for (int i = 0; i < height; i++)
    {
        file.read(reinterpret_cast<char *>(&pixels[i * row_padded]), row_padded);
    }

    file.close();
    return pixels;
}

bool writeBMPGrayscale(const std::string &filename, const unsigned char *pixels, int width, int height)
{
    int bitCount = 24;
    int row_padded = (width * 3 + 3) & (~3);
    int imageSize = row_padded * height;

    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;

    fileHeader.bfType = 0x4D42; // 'BM' in little-endian
    fileHeader.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + imageSize;
    fileHeader.bfReserved1 = 0;
    fileHeader.bfReserved2 = 0;
    fileHeader.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    infoHeader.biSize = sizeof(BITMAPINFOHEADER);
    infoHeader.biWidth = width;
    infoHeader.biHeight = height;
    infoHeader.biPlanes = 1;
    infoHeader.biBitCount = bitCount;
    infoHeader.biCompression = 0;
    infoHeader.biSizeImage = imageSize;
    infoHeader.biXPelsPerMeter = 0;
    infoHeader.biYPelsPerMeter = 0;
    infoHeader.biClrUsed = 0;
    infoHeader.biClrImportant = 0;

    std::ofstream file(filename, std::ios::binary);
    if (!file)
    {
        std::cerr << "Error opening file for writing." << std::endl;
        return false;
    }

    file.write(reinterpret_cast<char *>(&fileHeader), sizeof(BITMAPFILEHEADER));
    file.write(reinterpret_cast<char *>(&infoHeader), sizeof(BITMAPINFOHEADER));

    std::vector<unsigned char> row(row_padded);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            unsigned char grayscale = pixels[i * width + j];
            row[j * 3 + 0] = grayscale; // Blue
            row[j * 3 + 1] = grayscale; // Green
            row[j * 3 + 2] = grayscale; // Red
        }
        file.write(reinterpret_cast<char *>(row.data()), row_padded);
    }

    file.close();
    return true;
}