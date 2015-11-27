#include "boundaryFill.h"

int main(int argc, char ** argv) {
    int gd = DETECT, gm = VGAMAX;

    initgraph(&gd, &gm, NULL);

    setcolor(7);
    rectangle(100, 100, 300, 300);

    //-- Uncomment the following line to find out where the algorithm fails
    //setcolor(2);

    rectangle(200, 200, 400, 400);
    circle(400, 200, 60);

    boundaryFill(110, 110, 4, 7);
    boundaryFill(380, 380, 2, 7);
    boundaryFill(220, 220, 14, 7);
    boundaryFill(400, 180, 1, 7);
    boundaryFill(380, 210, 3, 7);

    getch();
    closegraph();

    return 0;
}