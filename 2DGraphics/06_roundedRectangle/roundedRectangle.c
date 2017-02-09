#include "roundedRectangle.h"

void roundedRectangle(int x0, int y0, int x1, int y1, int r, int color) {
    int xc0, yc0, xc1, yc1;

    /* Draw rounded corners */
    xc0 = x0 + r;
    yc0 = y0 + r;
    xc1 = x1 - r;
    yc1 = y1 - r;

    Circle(xc0, yc0, xc1, yc1, r, color);

    /* Draw lines */
    setcolor(color);

    line(x0 + r, y0, x1 - r, y0);       //-- TOP
    line(x1, y0 + r, x1, y1 - r);       //-- RIGHT
    line(x0 + r, y1, x1 - r, y1);       //-- BOTTOM
    line(x0, y0 + r, x0, y1 - r);       //-- LEFT
}