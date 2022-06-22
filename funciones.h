#include <math.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
int numeroDiscos, anchoDiscos, chunksPorLeer;
#define CANT_DISCO (4)
float media_real, media_imaginaria, potencia, ruido_total, masterArray[2][4];
pthread_mutex_t mutex;

void openFile(char* name);
void* trabajoHebras();
float originDistance(float u, float v);
int getIndexProccess(int numeroDiscos, int anchoDiscos, float oDistance);
void readfile();