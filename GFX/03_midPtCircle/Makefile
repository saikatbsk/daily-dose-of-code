LIBS=-lX11 -lm
GFXLIB='../../libgfx/gfx.c'

all: a.out

a.out: main.c
	gcc -o $@ $< $(GFXLIB) $(LIBS)

clean:
	rm -v *.out
