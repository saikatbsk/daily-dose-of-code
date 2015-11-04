all: hello.o
	ld -melf_i386 -s -o hello $<

hello.o: hello.asm
	nasm -f elf -o $@ $<

cleanall:
	rm -v hello *.o
