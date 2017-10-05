#include <stdio.h>
#include "mpi.h"

int main(int argc,char *argv[]){
	int a, i, sum, sumTotal, maxVal, interv, mod;
	int start, end, size, rank;
	maxVal = 10000;

	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	// Defina aqui el segmento que debe procesar una tarea
	// El inicio del segmento en la variable 'start', el fin del segmento
	// la variable 'end'
	interv=maxVal/size;
	mod=maxVal%size;
	start=interv*rank+1;
	end=interv*rank+interv;
	if(rank==size-1){
		end=end+mod;
	}
	
	sum = 0;
	for(i=start; i<= end; i++){
		sum = sum +i;
	}
	
	// Utilice la funcion 'MPI_Reduce' para guardar en la variable 
	// 'sumTotal' la suma parcial de todos las tareas 
	printf ("Procces %d - Sum from %d to %d\n",rank, start, end);
	MPI_Reduce(&sum, &sumTotal, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
	if(rank==0){
		printf ("\nTotal Sum from 1 to %d: %d\n",maxVal,sumTotal);
	}
	MPI_Finalize();
	
	return 0;
}



