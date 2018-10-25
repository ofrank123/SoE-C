#ifndef SIEVE
#define SIEVE

typedef unsigned char BYTE;

int sieve(int n);
BYTE * zero_mem(BYTE * a, int l);
BYTE * sieve_factors(int l, BYTE * a, int f);
#endif
