/* Utility functions for heat equation solver
 *   NOTE: This file does not need to be edited! */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "heat.h"

/* Utility routine for allocating a two dimensional array */
double **malloc_2d(int nx, int ny)
{
    double **array;
    int i;

    /* TODO: Add here the 2D array allocation */
    array = (double **) malloc((nx + 2) * sizeof(double *));
    array[0] = (double *) malloc((nx + 2) * (ny + 2) * sizeof(double));
    for (int k=0; k < (nx + 2); k++) {
	    array[k] = array[0] + k * (ny + 2); 
    }
    
	//#error Add allocation of 2D array

    return array;
}

/* Utility routine for deallocating a two dimensional array */
void free_2d(double **array)
{
    free(array[0]);
    free(array);
}


/* Copy data on temperature1 into temperature2 */
void copy_field(field *temperature1, field *temperature2)
{
    assert(temperature1->nx == temperature2->nx);
    assert(temperature1->ny == temperature2->ny);
    memcpy(temperature2->data[0], temperature1->data[0],
           (temperature1->nx + 2) * (temperature1->ny + 2) * sizeof(double));
}

/* Swap the data of fields temperature1 and temperature2 */
void swap_fields(field *temperature1, field *temperature2)
{
    double **tmp;
    tmp = temperature1->data;
    temperature1->data = temperature2->data;
    temperature2->data = tmp;
}
