all: main.cpp getValue.o
	g++ -o getvalue.out main.cpp getValue.o

getValue.o: getValue.asm
	nasm -f elf64 -o getValue.o getValue.asm

clean:
	rm -v *.o

cleanall:
	rm -v *.o *.out
