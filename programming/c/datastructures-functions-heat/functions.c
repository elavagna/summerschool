#include <stdio.h>
#include <cmath.h>
#include <stdlib.h>
#include "functions.h"

void initial_field(field* temp) {

    int i, j;

    temp->nx = nx;
    temp->ny = ny;
    temp->dx = DX;
    temp->dy = DY;
    temp->dx2 = pow(DX,2);
    temp->dy2 = pow(DY,2);

    // First initalize the inner values to zero
    for (i = 1; i < temp->nx - 1; i++) {
        for (j = 1; j < temp->ny - 1; j++) {
            temp->data[i][j] = 0.0;
        }
    }

    // Initial conditions for left and right
    for (i = 0; i < temp->nx; i++) {
        temp->data[i][0] = 20.0;
        temp->data[i][temp->ny + 1] = 70.0;
    }
    // and top and bottom boundaries
    for (j = 0; j < temp->ny; j++) {
        temp->data[0][j] = 85.0;
        temp->data[temp->nx + 1][j] = 5.0;
    }
}


void compute_laplacian(field* temp) {

    double laplacian[NX+2][NY+2];
    int i, j;

    // Evaluate the Laplacian
    // *INDENT-OFF*
    float dx2=DX*DX; float dy2= DY*DY;

    for (i = 1; i < temp->nx + 1; i++) {
	    for (j = 1; j < temp->ny + 1; j++) {
		    laplacian[i][j]=(temp->data[i-1][j]-2*temp->data[i][j]+temp->data[i+1][j])/dx2+(temp->data[i][j-1]-2*temp->data[i][j]+temp->data[i][j+1])/dy2;
	    }
    }

}
