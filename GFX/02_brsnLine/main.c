#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../../libgfx/gfx.h"
#define DEFAULTWIDTH  600
#define DEFAULTHEIGHT 400

void brsnLine(int x0, int y0, int x1, int y1) {
    int dx = abs(x0 - x1),
        dy = abs(y0 - y1),
        p  = 2 * dy - dx;   //-- Decision parameter
    int x, y, xEnd;

    /* Determine which point to use as start, which as end */
    if(x0 > x1) {
        x    = x1;
        y    = y1;
        xEnd = x0;
    }
    else {
        x    = x0;
        y    = y0;
        xEnd = x1;
    }

    /* Plot the initial point */
    gfx_point(x, y);

    /* Plot pixels at successive x intervals */
    while(x < xEnd) {
        x++;

        if(p < 0) {
            p += 2 * dy;
        }
        else {
            y++;
            p += 2 * dy - 2 * dx;
        }

        gfx_point(x, y);
    }
}

int main(int argc, char ** argv) {
    int x0, y0, x1, y1;
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

    printf("Provide the screen coordinates (x0, y0) and (x1, y1): ");
    scanf("%d %d %d %d", &x0, &y0, &x1, &y1);

    /* Open a new window for drawing */
    gfx_open(width, height, "BrsnLine");

    /* Set the current drawing color to green */
    gfx_color(0, 200, 100);

    /* Draw straight line DDALine algorithm */
    brsnLine(x0, y0, x1, y1);

    /* Wait for the user to press Escape */
    while((ch = gfx_wait()) != 27);

    return 0;
}
