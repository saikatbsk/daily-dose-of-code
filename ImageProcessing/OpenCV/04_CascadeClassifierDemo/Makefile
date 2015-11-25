LIBS = `pkg-config --libs opencv`

all : a.out

a.out : main.cpp
	g++ $< -o $@ $(LIBS)

clean :
	rm -v *.out

