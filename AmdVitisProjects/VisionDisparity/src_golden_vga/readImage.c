#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "sdvbs_common.h"

I2D *readImage(char const *pathName)
{
    char signature[2];
    int file_size;
    short reserved1;
    short reserved2;
    int loc_of_bitmap;
    int size_of_infoheader;
    int width;
    int height;
    short number_of_planes;
    short bits_per_pixel;
    int compression_method;
    int bytes_of_bitmap;
    int hori_reso;
    int vert_reso;
    int no_of_colors;
    int no_of_imp_colors;
    int nI, nJ;
    int pixSize;
    unsigned char tempb;
    unsigned char tempg;
    unsigned char tempr;
    unsigned char tempjunk[12];
    int ta;
    I2D *srcImage;
    FILE *input;
    input = fopen(pathName, "rb");
    if (input == ((void *)0))
    {
        perror("File pointer error");

        return ((void *)0);
    }
    else
    {
        fread(&signature, sizeof((signature)), 1, input);
        fread(&file_size, sizeof((file_size)), 1, input);
        fread(&reserved1, sizeof((reserved1)), 1, input);
        fread(&reserved2, sizeof((reserved2)), 1, input);
        fread(&loc_of_bitmap, sizeof((loc_of_bitmap)), 1, input);
        fread(&size_of_infoheader, sizeof((size_of_infoheader)), 1, input);
        fread(&width, sizeof((width)), 1, input);   // Reads the width of the image
        fread(&height, sizeof((height)), 1, input); // Reads the height of the image
        fread(&number_of_planes, sizeof((number_of_planes)), 1, input);
        fread(&bits_per_pixel, sizeof((bits_per_pixel)), 1, input);
        fread(&compression_method, sizeof((compression_method)), 1, input);
        fread(&bytes_of_bitmap, sizeof((bytes_of_bitmap)), 1, input);
        fread(&hori_reso, sizeof((hori_reso)), 1, input);
        fread(&vert_reso, sizeof((vert_reso)), 1, input);
        fread(&no_of_colors, sizeof((no_of_colors)), 1, input);
        fread(&no_of_imp_colors, sizeof((no_of_imp_colors)), 1, input);
        iMallocHandle(height, width, &srcImage);
        if (srcImage->height <= 0 || srcImage->width <= 0 || signature[0] != 'B' || signature[1] != 'M' || (bits_per_pixel != 24 && bits_per_pixel != 8))
        {
            printf("ERROR in BMP read: The input file is not in standard BMP format");

            return ((void *)0);
        }
        fseek(input, loc_of_bitmap, 0);
        if (bits_per_pixel == 8)
        {
            for (nI = (height - 1); nI >= 0; nI--)
            {
                for (nJ = 0; nJ < width; nJ++)
                {
                    fread(&tempg, sizeof(unsigned char), 1, input);
                    srcImage->data[(nI)*srcImage->width + (nJ)] = (int)tempg;
                }
            }
        }
        else
        {
            if (bits_per_pixel == 24)
            {
                for (nI = (height - 1); nI >= 0; nI--)
                {
                    for (nJ = 0; nJ < width; nJ++)
                    {
                        fread(&tempb, sizeof(unsigned char), 1, input);
                        fread(&tempg, sizeof(unsigned char), 1, input);
                        fread(&tempr, sizeof(unsigned char), 1, input);
                        ta = (3 * tempr + 6 * tempg + tempb) / 10;
                        ta = tempg;
                        srcImage->data[(nI)*srcImage->width + (nJ)] = (int)ta;
                    }
                }
            }
            else
            {

                return ((void *)0);
            }
        }
        fclose(input);

        return srcImage;
    }
}

// Function to write an integer as a little-endian byte sequence to a file
void write_int(FILE *file, uint32_t value)
{
    fwrite(&value, 4, 1, file);
}

// Function to write a short as a little-endian byte sequence to a file
void write_short(FILE *file, uint16_t value)
{
    fwrite(&value, 2, 1, file);
}

// Function to save an image as a BMP file
void save_bmp(const char *filename, int *pixels, int width, int height)
{
    FILE *file = fopen(filename, "wb");
    if (!file)
    {
        perror("Could not open file for writing");
        return;
    }

    // BMP file header
    uint32_t file_size = 54 + 3 * width * height; // 54 bytes for header, 3 bytes per pixel
    uint16_t bfType = 0x4D42;                     // 'BM' in little-endian
    fwrite(&bfType, 2, 1, file);                  // File type
    write_int(file, file_size);                   // File size
    write_short(file, 0);                         // Reserved1
    write_short(file, 0);                         // Reserved2
    write_int(file, 54);                          // Offset to pixel data

    // BMP info header
    write_int(file, 40);     // Info header size
    write_int(file, width);  // Width
    write_int(file, height); // Height
    write_short(file, 1);    // Planes
    write_short(file, 24);   // Bits per pixel
    write_int(file, 0);      // Compression (none)
    write_int(file, 0);      // Image size (can be 0 for no compression)
    write_int(file, 0);      // X pixels per meter
    write_int(file, 0);      // Y pixels per meter
    write_int(file, 0);      // Total colors
    write_int(file, 0);      // Important colors

    // Pixel data
    for (int y = height - 1; y >= 0; y--)
    { // BMP files are bottom to top
        for (int x = 0; x < width; x++)
        {
            int pixel = pixels[y * width + x];
            uint8_t r = (pixel >> 16) & 0xFF;
            uint8_t g = (pixel >> 8) & 0xFF;
            uint8_t b = pixel & 0xFF;
            fputc(b, file);
            fputc(g, file);
            fputc(r, file);
        }
    }

    fclose(file);
}
