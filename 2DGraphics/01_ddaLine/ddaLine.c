#include "ddaLine.h"

void ddaLine(int x0, int y0, int x1, int y1, int color) {
    int   dx, dy, steps, i;
    float x, y, xInc, yInc;

    /* Compute the change along x-axis and y-axis */
    dx = x1 - x0;
    dy = y1 - y0;

    /* Compute the deflection for both x and y at each step */
    if(abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);

    xInc = dx / (float)steps;
    yInc = dy / (float)steps;

    /* Set the initial values of x and y */
    x = x0; y = y0;

    /* Plot the line starting from (x0, y0) to (x1, y1) */
    putpixel(ROUND(x), ROUND(y), color);

    for(i = 0 ; i < steps ; i++) {
        x += xInc;
        y += yInc;

        putpixel(ROUND(x), ROUND(y), color);
    }

    return;
}
