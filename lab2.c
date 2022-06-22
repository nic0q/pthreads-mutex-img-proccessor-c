#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "funciones.h"
int n = 0, discWidth = 0, chunk = 0, threads = 0, option,
    b = 0;  // Se definen las variables a utilizar
int main(int argc, char *argv[]) {
  char *inputFile = NULL, *outputFile = NULL;
  while ((option = getopt(argc, argv, "i:o:n:d:h:c:b")) != -1) {
    switch (option) {
      case 'i':  // nombre del archivo de entrada
        inputFile = optarg;
        break;
      case 'o':  // nombre del archivo de salida
        outputFile = optarg;
        break;
      case 'n':  // numero de discos
        sscanf(optarg, "%d", &n);
        break;
      case 'd':  // ancho de cada disco
        sscanf(optarg, "%d", &discWidth);
        break;
      case 'h':  // cantidad de hebras
        sscanf(optarg, "%d", &threads);
        break;
      case 'c':  // número de líneas que la hebra lee por vez
        sscanf(optarg, "%d", &chunk);
        break;
      case 'b':  // bandera | flag | opcional
        b = 1;
        break;
      case '?':
        exit(0);
      default:  // En caso que no se haya ingresado alguna flag obligatoria, se
                // aborta la ejecucion
        abort();
    }
  }
  // Verificaciones
  if (n <= 0) {
    printf("numero de discos inválido\n");
    return 0;
  }
  if (threads <= 0) {
    printf("Cantidad hebras invalida\n");
    return 0;
  }
  if (chunk <= 0) {
    printf("chunk invalido\n");
    return 0;
  }
  if (discWidth <= 0) {
    printf("chunk invalido\n");
    return 0;
  }
  // printf("%d %d %d ", threads, chunk, b);
  numeroDiscos = n;
  anchoDiscos = discWidth;
  chunksPorLeer = chunk;
  openFile(inputFile);
 // pthread_t id;  // Identificador de la hebra
  // pthread_attr_t *hebras;
  void *status;
  cantidadde_lineas = 0;
  pthread_t threadsArray[threads];
  arrayMaster = (float**)calloc(numeroDiscos,sizeof(float*));
  for(int i = 0; i < 3; i++){
    arrayMaster[i] = (float*) calloc(3,sizeof(float));
  }
  pthread_mutex_init(&mutex, NULL);
  for (int tid = 0; tid < threads; tid++) {
    pthread_create(&threadsArray[tid], NULL, trabajoHebras, (void*) tid);
    //printf("id: %d\n", i);
  }
  for (int tid = 0; tid < threads; tid++) {
    pthread_join(threadsArray[tid], &status);
  }
  for(int i = 0; i < numeroDiscos; i++){
    printf("Ruido: %f\n", arrayMaster[i][2]);
  }
}