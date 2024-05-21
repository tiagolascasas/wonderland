typedef struct
{
    int width;
    int height;
    int *data;
} I2D;

#define MAX_IMG_SIZE 640*480

typedef struct
{
    int width;
    int height;
    int data[MAX_IMG_SIZE];
} I2D_fixed;

