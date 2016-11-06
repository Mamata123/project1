project: main.o grep.o
	cc main.o grep.o -o project
grep1.o: grep.o grep.h
	cc  -c grep.c
ma.o: main.o grep.h
	cc  -c main.c

