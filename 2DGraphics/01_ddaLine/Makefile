all: a.out

a.out: main.c ddaLine.c
	gcc -o $@ main.c ddaLine.c -lgraph -lm

clean:
	rm -v *.out
