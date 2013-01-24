
CFLAGS= -I/usr/local/include
LDFLAGS=-levent

all:basic

basic: basic.o
	$(CC) -o basic basic.o $(CFLAGS) $(LDFLAGS)
clean:
	rm *.o -rf
