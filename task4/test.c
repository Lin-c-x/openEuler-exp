#include <stdio.h> 
#include "bf_malloc.c" 
int main(int argc, char *argv[]) { 
  int need[10] = {8192,1145,4514,16800,7800,520,2048,4096,800,7777}; 
  int* arrays[10]; 
  int i, j, k; 
  for (k = 0; k < 2; k++) { 
    for (i = 0; i < 6; i++) { 
      arrays[i] = (int *)bf_malloc(sizeof(int) * need[i + 5 * k]); 
    } 
    for (i = 0; i < 6; i++) { 
      free(arrays[i]);
    } 
  } 
  return 0;
}
