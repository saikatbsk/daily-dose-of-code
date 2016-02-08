LIBS = `pkg-config --libs opencv`

all : a.out

a.out : main.cpp helper.cpp
	g++ main.cpp helper.cpp -o $@ $(LIBS)

clean :
	rm -v *.out

