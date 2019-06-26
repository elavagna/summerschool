#include <stdio.h>
#include <stdlib.h>

void add_one_to_both(int *a, int*b) {
  (*a)++;
  (*b)++;
}

int main(int argc, char *argv[]) {
  int A = 0;
  int B = 2;

  printf("First argument: %s\n", argv[1]);

  int C = atoi(argv[1]);
  
  printf("First argument: %d\n", C);

  add_one_to_both(&A,&C);

  printf("%d \t %d\n", A, C);
}
