#include "ddaLine.h"

/*
 * Digital Differential Analyzer  is a scan-conversion line algorithm
 * based on calculating either dx or dy.  We sample the line  at unit
 * intervals, and calculate the corresponding interger values nearest
 * to line path in the other coordinate.
 */
void ddaLine(int x0, int y0, int x1, int y1, int color) {
    int   dx, dy, steps, i;
    float xInc, yInc, x, y;

    /*
     * Calculate displacement  along x,  and y-axis
     * To handle  negative  changes we  do not take
     * ablosute values here
     */
    dx = x1 - x0;
    dy = y1 - y0;

    /* Determine incremental change along both axis */
    if(abs(dx) > abs(dy))
        steps = dx;
    else
        steps = dy;

    xInc = dx / (float)steps;
    yInc = dy / (float)steps;

    /*
     * Draw the initial point   on screen which  is
     * (x0 , y0). We don't care about the direction
     * of propagation of the line as we have  taken
     * care of the  negative changes  in dx, and dy
     */
    putpixel(ROUND(x0), ROUND(y0), color);

    /* Plot, and draw  successive points  on screen */
    for(i = 0 ; i < steps ; i++) {
        x += xInc;
        y += yInc;

        putpixel(ROUND(x), ROUND(y), color);
    }

    return;
}
