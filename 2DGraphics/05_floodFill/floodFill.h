#ifndef _FLOODFILL_H_
#define _FLOODFILL_H_

#include <graphics.h>
#include <math.h>

void floodFill(
        int x, int y,
        int fillcolor,              //-- Fill color
        int oldcolor                //-- Old color of the pixel
        );

#endif
