#include <stdio.h>

int main(int argc, char *argv[])
{
    int i;

    // write the control structure as described in the exercise
    // and run the code with different values for i

    while (1) {

      printf("Give me a integer number (-1 to exit):\t");
      scanf("%d", &i);
      if(i==-1) break;
      
      if (i==0) printf("Integer i = 0\n");
      else if (i<0) printf("Integer i < 0\n");
      else if (i>100) printf("Integer i > 100\n");
      else printf("Go on\n");

    }
    
    return 0;
}
