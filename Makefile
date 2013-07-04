CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=src/btree.c src/queue_test.c
EXECUTABLE=bin/btree bin/queue

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CC) $(LDFLAGS) $(SOURCES) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf src/*o bin/*exe

queue: src/queue_test.c
	$(CC) $(LDFLAGS) src/queue_test.c -o bin/$@

btree: src/btree.c
	$(CC) $(LDFLAGS) src/btree.c -o bin/$@

archive:
		rm -rf znds.tar.gz
		make all
		tar -cf znds.tar bin/*.exe
		gzip znds.tar

