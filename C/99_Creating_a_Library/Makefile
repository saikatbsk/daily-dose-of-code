CFLAGS = -c -fpic
CFLAGS_SHARED_LIB = -shared

all : libfilereader

libfilereader:
	gcc $(CFLAGS) -o lib/filereader.o lib/filereader.c
	ar rc lib/libfilereader.a lib/filereader.o
	gcc $(CFLAGS_SHARED_LIB) -o lib/libfilereader.so lib/filereader.o

clean:
	rm -v lib/*.o lib/*.so lib/*.a

