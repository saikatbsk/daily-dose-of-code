#include "roundedRectangle.h"

void Circle(int xc0, int yc0, int xc1, int yc1, int radius, int color) {
    int x, y, p;
    void plotCirclePoints(int, int, int, int, int, int, int);

    /* Initial values of x, y, and decision parameter p */
    x = 0;
    y = radius;
    p = 1 - radius;

    /* Plot the initial points */
    plotCirclePoints(xc0, yc0, xc1, yc1, x, y, color);

    /* Plot the remaining circle points */
    while(x < y) {
        x++;

        if(p < 0)
            p += (2 * x) + 3;
        else {
            y--;
            p += 2 * (x - y) + 5;
        }

        plotCirclePoints(xc0, yc0, xc1, yc1, x, y, color);
    }

    return;
}

void plotCirclePoints(int xc0, int yc0, int xc1, int yc1, int x, int y, int color) {
    putpixel(xc0 - y, yc0 - x, color);
    putpixel(xc0 - x, yc0 - y, color);
    putpixel(xc1 + y, yc0 - x, color);
    putpixel(xc1 + x, yc0 - y, color);
    putpixel(xc0 - x, yc1 + y, color);
    putpixel(xc0 - y, yc1 + x, color);
    putpixel(xc1 + x, yc1 + y, color);
    putpixel(xc1 + y, yc1 + x, color);
}
