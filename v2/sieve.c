#include "sieve.h"
#include <math.h>
#include <stdlib.h>
#define ODD_TO_IND(n) (((n - 1) / 2) - 1)


BYTE * sieve_factors(int l, BYTE * a, int f) {
  for(int i = (f*f); i < l; i+=(f*2)) {
    a[ODD_TO_IND(i)] = 1;
  }
  return a;
}

int sieve(int n) {
  if(n == 1) {return 2;}
  int l = n > 5000 ? (int) ((1.15 * n * log(n)) / 2) : (int) ((1.3 * n * log(n) + 10) / 2);
  BYTE * nums = (BYTE *) calloc(1, l);
  int i = 3;
  int curr;
  while(n-1) {
    if(i < sqrt(l*2)) {
      while(nums[ODD_TO_IND(i)]) {
        i+=2;
      }
      curr = i;
      sieve_factors(l * 2, nums, curr); 
      i+=2;
      n--;
    } else {
      while(nums[ODD_TO_IND(i)]) {
        i+=2;
      }
      curr = i;
      i+=2;
      n--;
    } 
  }
  free(nums);
  return curr;
}

