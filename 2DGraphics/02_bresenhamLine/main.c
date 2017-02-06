#include "bresenhamLine.h"

int main(int argc, char ** argv) {
    int gd = DETECT, gm = VGAMAX;

    initgraph(&gd, &gm, NULL);

    bresenhamLine(0, 0, 220, 330, 4);

    getch();
    closegraph();

    return 0;
}