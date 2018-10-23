#include "sieve.h"
#include <math.h>
#include <stdlib.h>

#define ODD_TO_IND(n) (((n - 1) / 2) - 1)
#define IND_TO_ODD(n) (((n + 1) * 2) + 1)

BYTE * sieve_factors(int l, BYTE * a, int f) {
  for(int i = ODD_TO_IND(f*f); i < l; i+=f) {
    a[i] = 1;
  }
  return a;
}

int sieve(int n) {
  if(n == 1) {return 2;}
  int l = n > 5000 ? (int) ((1.15 * n * log(n)) / 2) : (int) ((1.3 * n * log(n) + 10) / 2);
  BYTE * nums = (BYTE *) calloc(1, l);
  int i = 0;
  int curr;
  int max = (int) sqrt(l*2);
  while(n-1) {
    if(IND_TO_ODD(i) < max) {
      while(nums[i]) {
        i++;
      }
      curr = IND_TO_ODD(i);
      sieve_factors(l, nums, curr); 
      i++;
      n--;
    } else {
      while(nums[i]) {
        i++;
      }
      curr = IND_TO_ODD(i);
      i++;
      n--;
    } 
  }
  free(nums);
  return curr;
}

