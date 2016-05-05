/*
 * Implementation of Trapezoidal Rule
 */

#include <stdio.h>
#include <stdlib.h>
#define f(x) x*x*x

int main(int argc, char ** argv) {
    float a /* lower limit */, b /* upper limit */, h /* segmentation width */;
    int n;  /* number of intervals */
    int nData;
    int i;

    if(argc < 2) {
        printf(">>> No input file specified!\n");
        printf("Usage: a.out <input_file>\n");

        return -1;
    }

    FILE * fp;
    if(!(fp = fopen(argv[1], "r+"))) {
        printf(">>> Error! Input file does not exist.\n");
        return -1;
    }

    //-- scanning number of data
    fscanf(fp, "%d", &nData);

    while(nData > 0) {
        //-- scan data from input file
        fscanf(fp, "%f %f %d", &a, &b, &n);

        //-- calculating the segmentation width
        h = (b - a) / n;

        //-- check if solution is possible
        if((a + h) > b) {
            printf(">>> A solution is NOT possible with these inputs!!\n");
        }
        else {
            //-- calculating the value of f(x)
            float pt1 = f(a) + f(b);
            float pt2;

            for(i = 1 ; i < n ; i++) {
                float x = a + (i * h);
                pt2 += f(x);
            }

            float I = (h/2) * (pt1 + 2*pt2);

            printf("ll = %f, ul = %f, interval = %d, f(x) = %f\n", a, b, n, I);
        }

        nData--;
    }

    fclose(fp);

    return 0;
}
