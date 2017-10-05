# Electiva-Fall-2017-1601819

Jenniffer Sidney Guerrero Prado

Código 1601819

Este Directorio contiene ejercicios para mostrar el manejo de diferentes instrucciones usando MPI

## mpiEx2a.c
Uso de las funciones `MPI_Comm_size` y `MPI_Comm_rank`

## mpiEx2b.c
programa en el cual **SOLO** el maestro imprime el numero total de procesos en ejecucion

## mpiEx3a.c
Programa en el que en lugar de intercambiar caracteres, se intercambien enteros.

## mpiEx3b.c
Programa de intercambio de mensasjes entre procesos siguiendo una topología en anillo

## mpiExample4.c
Programa que calcula la suma de los primeros **X** numeros de forma distribuida.
El parametro `x` puede ser definido por el usuario

## mpiEx4a.c
Programa que estima el valor de **PI** aplicando el metodo montecarlo y la instruccion
`MPI_Reduce`.
	* Por que piensa que es importante MPI en un problema como el del calculo de **pi** usando la aproximacion Montecarlo?
	Porque en este caso se requiere de un gran número de calculos no secuenciales ni dependientes, por lo cual es útil dividirlos entre diferentes
	unidades de procesamiento disponibles.
	
	* Para que tipo de problemas entonces es apropiado MPI?
	Cuando se requieren realizar procesos que pueden hacerse de forma paralela, es decir, que el resultado de un proceso no depende
	de un resultado anterior. Caso de ejemplo, es el calculo de PI con el algoritmo de Montecarlo. 

## Axb.c
Programa que la multiplicacion matrix x vector y distribuye su calculo entre
las unidades de procesamiento disponibles
