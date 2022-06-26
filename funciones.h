#include <stdlib.h>
#include <stdio.h>
#include <math.h> 

// Cabeceras de funciones
void imprimirProps(int n, float**arrayMaster);
int getIndexProccess(int numeroDiscos, int anchoDiscos, float oDistance);
float originDistance(float u, float v);
void escribirSalida(int nProcesses, char *outputFile, float** datos);