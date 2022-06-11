#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "funciones.h"

int main(int argc, char *argv[]) {
  // Se definen las variables a utilizar
  int n = 0, discWidth = 0, chunks = 0, threads = 0, option, IDchild = 0, b = 0;
  char *inputFile = NULL, *outputFile = NULL;
  pid_t pid;
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
      case 'h':  // ancho de cada disco
        sscanf(optarg, "%d", &threads);
        break;
      case 'c':  // ancho de cada disco
        sscanf(optarg, "%d", &chunks);
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
  printf("%d %d %d ", threads, chunks, b);
}