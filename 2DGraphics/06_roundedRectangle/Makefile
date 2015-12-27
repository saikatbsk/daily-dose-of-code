all: a.out

a.out: main.c roundedRectangle.c modifiedMidPtCircle.c
	gcc -o $@ main.c roundedRectangle.c modifiedMidPtCircle.c -lgraph -lm

clean:
	rm -v *.out
