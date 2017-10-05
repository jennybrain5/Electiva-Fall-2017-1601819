#include <stdio.h>
#include "mpi.h"

int main(int argc,char *argv[]){
	int a, size, rank, dest, source, count, tag=1;
	char inmsg, outmsg='x';
	MPI_Status Stat;

	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if (rank == 0) {
	  dest = rank+1;
	  source = size-1;
	  MPI_Send(&outmsg, 1, MPI_CHAR, dest, tag, MPI_COMM_WORLD);
	  MPI_Recv(&inmsg, 1, MPI_CHAR, source, tag, MPI_COMM_WORLD, &Stat);
	}else {
		for (a=1; a<size; a=a+1){
			if(rank==a){
				source = a-1;
				if(a==size-1){
					dest = 0;
				}
				else{
					dest=a+1;
				}
			MPI_Recv(&inmsg, 1, MPI_CHAR, source, tag, MPI_COMM_WORLD, &Stat);
			MPI_Send(&outmsg, 1, MPI_CHAR, dest, tag, MPI_COMM_WORLD);		
			}
		}
	}

	MPI_Get_count(&Stat, MPI_CHAR, &count);
	printf("Message: %c - Task %d: Received %d char(s) from task %d with tag %d. Message sent to task %d \n",
		   outmsg, rank, count, Stat.MPI_SOURCE, Stat.MPI_TAG, dest);

	MPI_Finalize();
}



