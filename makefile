all: sieve.o sieve.h test.c
	gcc -g test.c sieve.o -o test -lm

run: 
	./test ${args}

debug: all
	gdb -tui test

sieve.o: sieve.h sieve.c
	gcc -g -c sieve.c -lm

clean:
	rm *.o test
