#include <stdio.h>
#include <stdlib.h>

#define NX 10
#define NY 10

int main(void)
{
    int i, j;
    // Add here the definition for array with name 'array'
    // of size NX times NY (258x258)
    //#error Define the array
    float** array = malloc(NX * sizeof(float *));
    array[0] = malloc(NX * NY * sizeof(float));
    for (int k=0; k<NX; k++) {
	    array[k] = array[0] + k * NY; 
    }

    // Initialize first the zeros
    //#error Initialize the zeros for interior
    for (i=1; i<NX-1; i++) {
	    for (j=1; j<NY-1; j++) {
		    array[i][j]=0;
	    }
    }

    // Initial conditions for left and right
    for (j=0; j<NY; j++) {
	    array[j][0]=20;
	    array[j][NY-1]=70;
    }
//#error add boundary conditions for left and right

    // and top and bottom boundaries
    for (i=0; i<NX; i++) {
	    array[0][i]=85;
	    array[NX-1][i]=5;
    }
//#error add boundary conditions for top and bottom

    for (i=0; i<NX; i++) {
    	for (j=0; j<NY; j++) {
	    printf("%.1f\t",array[i][j]);
	}
	printf("\n");
    }

    return 0;
}
