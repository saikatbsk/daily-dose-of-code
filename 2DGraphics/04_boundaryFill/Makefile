all: a.out

a.out: main.c boundaryFill.c
	gcc -o $@ main.c boundaryFill.c -lgraph -lm

clean:
	rm -v *.out
