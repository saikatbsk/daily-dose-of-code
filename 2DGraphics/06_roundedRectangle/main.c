#include "roundedRectangle.h"

int main(int argc, char ** argv) {
    int gd = DETECT, gm = VGAMAX;

    initgraph(&gd, &gm, NULL);

    roundedRectangle(100, 100, 400, 300, 20, 4);

    getch();
    closegraph();

    return 0;
}