 #include <stdlib.h> 
#include <time.h>
#include <stdio.h>

 

void matmul_par(double ** A, double ** B, double ** C, int row, int col, int common)
{

	#pragma omp parallel for 

	for ( int i = 0; i < row; i++) 
	{
 		for (int j = 0; j < col; j++)
		{
			int sum = 0;
			for (int k = 0; k < common; k++)
			{
				sum += A[i][k] * B[k][j];
			}
			C[i][j] = sum;
		}
	}
 }


 int main(void){

 	
    const double a_row=4000, b_col=1000, a_col_b_row=1000;
	int i;
	double ** a =  malloc(sizeof(double*) * a_row);
	for( i =0; i< a_row; i++){
		a[i] = malloc(sizeof(double) * a_col_b_row);
	}

	double ** b = malloc(sizeof(double*) * a_col_b_row);
	for( i = 0; i< a_col_b_row; i++){
		b[i] = malloc(sizeof(double) * b_col);
	}

	double ** c = malloc(sizeof(double*) * a_row);
	for( i = 0; i< a_row; i++){
		c[i] = malloc(sizeof(double) * b_col);
	}
 
	matmul_par(a,b,c, a_row,b_col, a_col_b_row);

	 
 
	return 0;
 }

