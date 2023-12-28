CC=gcc

all: mylloc.c
	$(CC) -o mylloc mylloc.c

clean:
	rm -v mylloc
