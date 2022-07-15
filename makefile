CC = gcc
CFLAGS = -Wall -std=c99 -c -g -D_DEFAULT_SOURCE

gps: gps.o libfiles.o libbikes.o
	$(CC) gps.o libfiles.o libbikes.o -o gps

main: gps.c
	$(CC) $(CFLAGS) gps.c 

libfiles: libfiles.c
	$(CC) $(CFLAGS) libfiles.c

libbikes: libbikes.c
	$(CC) $(CFLAGS) libbikes.c

clean:
	rm *.o gps
