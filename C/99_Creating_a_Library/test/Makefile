all : test

test:
	gcc -o test test.c -L../lib -lfilereader -I../include

static_lib:
	gcc --static -o test test.c -L../lib -lfilereader -I../include

clean:
	rm -v test

