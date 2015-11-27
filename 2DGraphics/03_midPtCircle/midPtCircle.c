#include "midPtCircle.h"

void midPtCircle(int xCenter, int yCenter, int radius, int color) {
    int x, y, p;
    void plotCirclePoints(int, int, int, int, int);

    /* Initial values of x, y, and decision parameter p */
    x = 0;
    y = radius;
    p = 1 - radius;

    /* Plot the initial points */
    plotCirclePoints(xCenter, yCenter, x, y, color);

    /* Plot the remaining circle points */
    while(x < y) {
        x++;

        if(p < 0)
            p += (2 * x) + 3;
        else {
            y--;
            p += 2 * (x - y) + 5;
        }

        plotCirclePoints(xCenter, yCenter, x, y, color);
    }

    return;
}

void plotCirclePoints(int xCenter, int yCenter, int x, int y, int color) {
    putpixel(xCenter + x, yCenter + y, color);
    putpixel(xCenter - x, yCenter + y, color);
    putpixel(xCenter + x, yCenter - y, color);
    putpixel(xCenter - x, yCenter - y, color);
    putpixel(xCenter + y, yCenter + x, color);
    putpixel(xCenter - y, yCenter + x, color);
    putpixel(xCenter + y, yCenter - x, color);
    putpixel(xCenter - y, yCenter - x, color);
}
