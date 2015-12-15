#include "bresenhamLine.h"

/*
 * Instead of using  floating point arithmatic,  and  operations like
 * multiplication, and division which are slow, highly expensive, and
 * inefficient as in  DDA line drawing algorithm,   here we are using
 * Bresenham's line drawing algorithm  which is  based on incremental
 * integer arithmatic.
 */
void bresenhamLine(int x0, int y0, int x1, int y1, int color) {
    int x, y, dx, dy, p, xEnd;

    /*  Calculate the change along x, and y-axis */
    dx = abs(x1 - x0);
    dy = abs(y1 - y0);

    /* Initial value  of the  decision parameter */
    p = 2 * dy - dx;

    /*
     * Calculate the initial values for x, and y; also determine xEnd
     * which is the final value for x
     */
    if(x1 > x0) {
        x = x0; y = y0; xEnd = x1;
    }
    else {
        x = x1; y = y1; xEnd = x0;
    }

    /*
     * Plot the  starting pixels first, then  incrementally determine
     * the rest of the pixels to be drawn by calculating the decision
     * variable at each iteration
     */
    putpixel(x, y, color);

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
