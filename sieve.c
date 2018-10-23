#include "sieve.h"
#include <math.h>
#include <stdlib.h>

#define ODD_TO_IND(n) (((n - 1) / 2) - 1)
#define IND_TO_ODD(n) (((n + 1) * 2) + 1)
#define SET_BIT(l, i) (l[i/8] | (1<<(i%8)))
#define GET_BIT(l, i) (l[i/8] & (1<<(i%8)))

int sieve(int n) {
  if(n == 1) {return 2;}
  int l = n > 5000 ? (int) ((1.15 * n * log(n)) / 2) : (int) ((1.3 * n * log(n) + 10) / 2);
  BYTE * nums = (BYTE *) calloc(1, l / 8);
  int i = 0;
  int curr;
  int max = (int) sqrt(l*2);
  while(n-1) {
    if(IND_TO_ODD(i) < max) {
      while(!~nums[i/8]) {
        i+=8;       
      }
      while(GET_BIT(nums, i)) {
        i++;
      }
      curr = IND_TO_ODD(i);
      for(int j = ODD_TO_IND(curr*curr); j<l; j+=curr) {
        nums[j/8] = SET_BIT(nums, j);
      }
      i++;
      n--;
    } else {
      while(!~nums[i/8]) {
        i+=8;
      }
      while(GET_BIT(nums, i)) {
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

