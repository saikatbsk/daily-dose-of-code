#include "bresenhamLine.h"

void bresenhamLine(int x0, int y0, int x1, int y1, int color) {
    int x, y, dx, dy, p, xEnd;

    /*  Compute the change along x-axis and y-axis */
    dx = abs(x1 - x0);
    dy = abs(y1 - y0);

    /* The initial value of the decision parameter */
    p = 2 * dy - dx;

    /* Set initial values for x, y and xEnd */
    if(x1 > x0) {
        x = x0; y = y0; xEnd = x1;
    }
    else {
        x = x1; y = y1; xEnd = x0;
    }

    /* Plot the starting pixel */
    putpixel(x, y, color);

    /* Plot the rest of the line, increment x till it reaches xEnd */
    while(x < xEnd) {
        x++;

        if(p < 0)
            p += 2 * dy;
        else {
            y++;
            p += 2 * dy - 2 * dx;
        }

        putpixel(x, y, color);
    }

    return;
}
