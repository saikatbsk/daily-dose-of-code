all: a.out

a.out: main.c midPtCircle.c
	gcc -o $@ main.c midPtCircle.c -lgraph -lm

clean:
	rm -v *.out
