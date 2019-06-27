#include <stdio.h>

int main(int argc, char **argv[])
{
  int f0, f1, f2, N;
  f0 = 0;
  f1 = 1;
  f2 = f1 + f0;
  N = (int) argv[1];

//  printf("Up to %s\n", argv[1]);
//  printf("Up to %d\n", N);
  printf("%d\n",f0);
  
  while (f2<N) {
    printf("%d\n",f2);
    f2 = f0 + f1;
    f0 = f1;
    f1 = f2;
  }
  
  // initialize variables and write the while loop
  // Remember to update all variables within the loop
  
  return 0;
}
