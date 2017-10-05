#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "mpi.h"

int main(int argc, char* argv[])
{
	int iters = 10e6;
	int rank, size, a, i, reducedcount, totaliters;
	double x,y,h;
	int count=0;
	double pi;
	
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	
	srand48(rank+time(NULL)); //random seed	
	for (i=0; i<iters; i++)			
	{
		x = (double)drand48();			//gets a random x coordinate
		y = (double)drand48();			//gets a random y coordinate
		h = ((x*x)+(y*y));			//Checks to see if number in inside unit circle
		if (h<=1){
			count++;			
		}	
	}			
	printf("Task %d: Mcounts= %d\n",rank,count);	
	
	
	
	MPI_Reduce(&count, &reducedcount, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
	
	if (rank == 0)					
	{      
		//pi = 4(m/n)
		totaliters=iters*size;
		pi = 4.0*((double)reducedcount/(double)totaliters);
		printf("\nTotalCounts M:%d, TotalIters N:%d\n",reducedcount,totaliters);			
		printf("Pi = 4*M/N = %f\n", pi);			
	}
	MPI_Finalize();						
	return 0;
}