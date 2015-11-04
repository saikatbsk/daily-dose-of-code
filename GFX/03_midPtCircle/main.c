#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../../libgfx/gfx.h"
#define DEFAULTWIDTH  800
#define DEFAULTHEIGHT 600

void plotCirclePoints(int xCenter, int yCenter, int x, int y) {
    gfx_point(xCenter + x, yCenter + y);
    gfx_point(xCenter - x, yCenter + y);
    gfx_point(xCenter + x, yCenter - y);
    gfx_point(xCenter - x, yCenter - y);
    gfx_point(xCenter + y, yCenter + x);
    gfx_point(xCenter - y, yCenter + x);
    gfx_point(xCenter + y, yCenter - x);
    gfx_point(xCenter - y, yCenter - x);
}

void midPtCircle(int xCenter, int yCenter, int radius) {
    int x = 0, y = radius;
    int p = 1 - radius;

    /* Plot first set of points */
    plotCirclePoints(xCenter, yCenter, x, y);

    while(x < y) {
        x++;

        if(p < 0) {
            p += 2 * x + 1;
        }
        else {
            y--;
            p += 2 * (x - y) + 1;
        }

        plotCirclePoints(xCenter, yCenter, x, y);
    }
}

int main(int argc, char ** argv) {
    int xc, yc, r;
    int width, height;
    char ch;

    if(argc < 3) {
        width  = DEFAULTWIDTH;
        height = DEFAULTHEIGHT;
    }
    else {
        width  = atoi(argv[1]);
        height = atoi(argv[2]);
    }

    printf("Provide the centre coordinates (xc, yc) and radius (r): ");
    scanf("%d %d %d", &xc, &yc, &r);

    /*  Open a new window for drawing */
    gfx_open(width, height, "MidPtCircle");

    /*  Set the current drawing color to green */
    gfx_color(0, 200, 100);

    /*  Draw circle using Mid Point Circle-drawing Algorithm */
    midPtCircle(xc, yc, r);

    /*  Wait for the user to press Escape */
    while((ch = gfx_wait()) != 27);

    return 0;
}
