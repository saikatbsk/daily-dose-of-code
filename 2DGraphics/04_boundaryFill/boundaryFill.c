#include "boundaryFill.h"

void boundaryFill(int x, int y, int fill, int boundary) {
    int current;

    /* Get the color of the current pixel that is (x, y) */
    current = getpixel(x, y);

    if((current != fill) && (current != boundary)) {
        putpixel(x, y, fill);

        /* Recursively fill the 4-connected area */
        boundaryFill(x + 1, y, fill, boundary);
        boundaryFill(x - 1, y, fill, boundary);
        boundaryFill(x, y + 1, fill, boundary);
        boundaryFill(x, y - 1, fill, boundary);
    }

    return;
}
