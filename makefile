CC=gcc
CFLAGS= -Wall -ansi -g -O3

wordmorph :  main.o fdic.o fprob.o heap.o quicks.o resolve.o tabpal.o imprimef.o
	$(CC) $(CFLAGS) -o wordmorph  main.o fdic.o fprob.o heap.o quicks.o resolve.o tabpal.o imprimef.o

main.o: main.c defs.h tabpal.h fprob.h fdic.h quicks.h resolve.h heap.h imprimef.h
	$(CC) -c $(CFLAGS) main.c

fdic.o: fdic.c fdic.h tabpal.h quicks.h defs.h fprob.h
	$(CC) -c $(CFLAGS) fdic.c

fprob.o: fprob.c defs.h fprob.h
	$(CC) -c $(CFLAGS) fprob.c

heap.o: heap.c defs.h heap.h
	$(CC) -c $(CFLAGS) heap.c

quicks.o: quicks.c quicks.h defs.h fprob.h
	$(CC) -c $(CFLAGS) quicks.c

resolve.o: resolve.c resolve.h tabpal.h defs.h heap.h fprob.h
	$(CC) -c $(CFLAGS) resolve.c

tabpal.o: tabpal.c tabpal.h defs.h fprob.h
	$(CC) -c $(CFLAGS) tabpal.c

imprimef.o: imprimef.c imprimef.h tabpal.h defs.h fprob.h
	$(CC) -c $(CFLAGS) imprimef.c

clean::
	rm -f *.o core a.out wordmorph *~