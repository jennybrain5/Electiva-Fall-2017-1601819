#include <mpi.h>
#include <stdio.h>

#define MAXARRAY 20

int iniarray(int n, int *array) {
	int i;
	for (i = 0; i < n; i++) 
		array[i] = i;
	return i;
}

void printarray(int n, int *array) {
	int i = 0;
	printf("[ ");
	for (; i < n; i++) {
		if (i == n - 1) 
			printf("%d ", array[i]);
		else
			printf("%d, ", array[i]);
	}
	printf("]\n");
}

void myBcast (void *data, int numelem, MPI_Datatype datatype, int root, MPI_Comm communicator){
	int rank, size;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Status Stat;
	
	if(rank==0){
		for (int i = 1; i < size; i++){
			MPI_Send(data,numelem,datatype,i,1,MPI_COMM_WORLD);
		}
		
	}
	else{
		MPI_Recv(data,numelem,datatype,0,1,MPI_COMM_WORLD, &Stat);
		
	}
}

int main(int argc, char** argv) {
	int arreglo[MAXARRAY];
	int rank;
	
	MPI_Init(NULL, NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	if (rank == 0) {
		iniarray(MAXARRAY, arreglo);
		//MPI_Bcast(arreglo, MAXARRAY, MPI_INT, 0, MPI_COMM_WORLD);
		myBcast(arreglo, MAXARRAY, MPI_INT, 1, MPI_COMM_WORLD);
	} else {
		if (rank == 1) {
			printf("Imprimiendo arreglo desde [%d]\n", rank);
			printarray(MAXARRAY, arreglo);
		}
		//MPI_Bcast(arreglo, MAXARRAY, MPI_INT, 0, MPI_COMM_WORLD);
		myBcast(arreglo, MAXARRAY, MPI_INT, 1, MPI_COMM_WORLD);
		if (rank == 1) {
			printf("Imprimiendo arreglo desde [%d]\n", rank);
			printarray(MAXARRAY, arreglo);
		}
	}
	MPI_Finalize();
}
