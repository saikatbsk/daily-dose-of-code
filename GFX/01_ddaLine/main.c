#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../../libgfx/gfx.h"
#define DEFAULTWIDTH  600
#define DEFAULTHEIGHT 400

#define ROUND(x) ((int)(x + 0.5))

void ddaLine(int x0, int y0, int x1, int y1) {
    int dx = x1 - x0,
        dy = y1 - y0;

    int steps, k;

    float xInc, yInc,
          x = x0, y = y0;

    if(abs(dx) > abs(dy)) steps = abs(dx);
    else steps = abs(dy);

    xInc = dx / (float)steps;
    yInc = dy / (float)steps;

    gfx_point(ROUND(x), ROUND(y));
    for(k = 0 ; k < steps ; k++) {
        x += xInc;
        y += yInc;
        gfx_point(ROUND(x), ROUND(y));
    }

    return;
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
    gfx_open(width, height, "DDALine");

    /* Set the current drawing color to green */
    gfx_color(0, 200, 100);

    /* Draw straight line DDALine algorithm */
    ddaLine(x0, y0, x1, y1);

    /* Wait for the user to press Escape */
    while((ch = gfx_wait()) != 27);

    return 0;
}
