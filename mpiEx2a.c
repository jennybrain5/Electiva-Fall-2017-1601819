#include <stdio.h>
#include "mpi.h"

int main(int argc, char* argv[]){
	int  rank, size;
	
	/* start up MPI */
	
	MPI_Init(&argc, &argv);
	
	/* find out process rank */
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	/* find out number of processes */
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	
	if( rank == 0 ) {

         /* do some work as master process */
		 printf("Yo soy el maestro y existen %d procesos corriendo\n", size);
      }
      else {

         /* do some work as other process*/
		 printf("Yo soy un proceso con identificador %d de %d procesos en ejecucion\n", rank, size);
      }
	

	/* shut down MPI */
	MPI_Finalize(); 
	
	return 0;
}