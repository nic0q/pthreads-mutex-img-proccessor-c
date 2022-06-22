#include <math.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
int numeroDiscos, anchoDiscos, chunksPorLeer;
pthread_mutex_t mutex;

void openFile(char* name);
void* trabajoHebras();
float originDistance(float u, float v);