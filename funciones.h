#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <unistd.h>

// Cabeceras de funciones
void escribirSalida(int nProcesses, char *nameOutputFile, float** datos);
int getIndexProccess(int nDisks, int diskWidth, float oDistance);
void imprimirProps(int n, float**array);
float originDistance(float u, float v);