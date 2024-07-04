typedef struct
{
    void *buffer;
    int width;
    int height;
    int pixelByteSize;
    char isGrayscale;
} TerminalBuffer;

TerminalBuffer *termbuf_create(int width, int height, int pixelByteSize, char isGrayscale);

void termbuf_clear(TerminalBuffer *buf);

void termbuf_render(TerminalBuffer *buf, void *data);
