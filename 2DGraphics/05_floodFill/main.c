#include "floodFill.h"

int main(int argc, char ** argv) {
    int gd = DETECT, gm = VGAMAX;

    initgraph(&gd, &gm, NULL);

    setcolor(4);
    rectangle(100, 100, 300, 300);

    //-- This is where boundary fill algorithm would have failed
    setcolor(2);

    rectangle(200, 200, 400, 400);
    circle(400, 200, 60);

    floodFill(110, 110, 4, 0);
    floodFill(380, 380, 2, 0);
    floodFill(220, 220, 14, 0);
    floodFill(400, 180, 1, 0);
    floodFill(380, 210, 3, 0);

    getch();
    closegraph();

    return 0;
}