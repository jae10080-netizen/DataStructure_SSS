#include <stdio.h>

int main(void) {
  int i, sale[4] = { 157, 209, 251, 312 };

  for(i = 0; i < 4; i++) {
    printf("address of : %u / sale[%d] = %d \n", &sale[i], i, sale[i]);

  }

  getchar(); return 0; 
}