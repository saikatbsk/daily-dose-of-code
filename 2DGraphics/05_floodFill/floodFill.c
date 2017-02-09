#include "floodFill.h"

void floodFill(int x, int y, int fillcolor, int oldcolor) {
    if(getpixel(x, y) == oldcolor) {
        putpixel(x, y, fillcolor);

        /* Recursively fill the 4-connected area */
        floodFill(x + 1, y, fillcolor, oldcolor);
        floodFill(x - 1, y, fillcolor, oldcolor);
        floodFill(x, y + 1, fillcolor, oldcolor);
        floodFill(x, y - 1, fillcolor, oldcolor);
    }

    return;
}
