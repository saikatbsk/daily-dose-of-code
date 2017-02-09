#include "ddaLine.h"

int main(int argc, char ** argv) {
    int gd = DETECT, gm = VGAMAX;

    initgraph(&gd, &gm, NULL);

    ddaLine(0, 0, 200, 300, 4);

    getch();
    closegraph();

    return 0;
}