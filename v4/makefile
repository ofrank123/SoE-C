all: sieve.o sieve.h test.c
	gcc -lm -g test.c sieve.o -o test

run: all 
	./test ${args}

debug: all
	gdb -tui test

sieve.o: sieve.h sieve.c
	gcc -lm -g -c sieve.c

clean:
	rm *.o test
