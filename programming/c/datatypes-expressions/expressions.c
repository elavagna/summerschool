#include <stdio.h>

int main(int argc, char *argv[])
{
    // declare integers, floats, and doubles
	int a=11;
	float f=19.94;
	double g;
	double h=12.811823;
	
    // evaluate expressions, e.g. c = a + 2.5 * b
    	g = a + 2*f;
	printf("Sum of a integer and a float (as a double) %.2f \n", g);

	g = f + h;
	printf("Sum of a float and a double (as a double) %.6f \n", g);

	(float) g;
	printf("Sum of a float and a double (as a float) %.6f \n", g);
	
    // and print out results. Try to combine integers, floats
    // and doubles and investigate what happens in type conversions

    return 0;
}
