#include <stdlib.h>
#include <graphics.h>

int main(int argc, char ** argv) {
    int gd = DETECT, gm = VGAMAX;

    initgraph(&gd, &gm, NULL);

    setcolor(4);
    line(0, 0, 100, 100);

    getch();
    closegraph();

    return 0;
}