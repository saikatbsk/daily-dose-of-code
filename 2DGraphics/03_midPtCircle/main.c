#include "midPtCircle.h"

int main(int argc, char ** argv) {
    int gd = DETECT, gm = VGAMAX;

    initgraph(&gd, &gm, NULL);

    midPtCircle(120, 120, 90, 4);

    getch();
    closegraph();

    return 0;
}