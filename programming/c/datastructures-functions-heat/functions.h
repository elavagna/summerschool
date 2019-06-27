#define NX 258
#define NY 258

#define DX 0.01
#define DY 0.01

#ifndef FUNCTIONS
#define FUNCTIONS

typedef struct {
	int nx, ny;
	float dx, dy;
	float dx2, dy2;
	float data[NX+2][NY+2];
} field;

void initial_field(field* );

void compute_laplacian(field* );

#endif
