CFLAGS = -Wall -fprofile-arcs -ftest-coverage -lm

default: testme.c
	gcc -o testme testme.c $(CFLAGS)

clean:
	rm -f testme *.o *.gcno *.gcov *.gcda
