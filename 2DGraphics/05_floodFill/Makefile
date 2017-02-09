all: a.out

a.out: main.c floodFill.c
	gcc -o $@ main.c floodFill.c -lgraph -lm

clean:
	rm -v *.out
