all: a.out

a.out: main.c bresenhamLine.c
	gcc -o $@ main.c bresenhamLine.c -lgraph -lm

clean:
	rm -v *.out
