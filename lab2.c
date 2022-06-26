#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "funciones.h"

int n = 0, discWidth = 0, chunk = 0, threads = 0, option, b = 0;  // Variables globales obtenidas mediante flags
float** arrayMaster;  // Puntero a arreglo bidimensional para almacenar las propiedades de cada punto a leer
FILE *f;  // Declaración del archivo mediante un FILE stream global
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;  // Declaración del mutex global
void *hebras(void *tid){
  long *myID = (long *)tid; // Id de cada hebra para verificar que el proceso se ejecuta de forma concurrente
  float u, v; // Varibles locales para almacenar la coordenada u y v de cada punto
  char buffer[256]; // Buffer para almacenar la linea leida del archivo
  while(feof(f) == 0){  // Mientras no se llegue al final de archivo
    pthread_mutex_lock(&mutex); // Se ingresa a la sección crítica
    float vis[3]; // Arreglo de 3 posiciones para almacenar [parte real, parte imaginaria, ruido] de cada punto
    for(int i = 0; i < chunk; i++){  // Iteracion para leer las líneas de cada chunk
      if(feof(f) != 0){ // Si se llegó al final del archivo, se sale del ciclo
        break;
      }
			fgets(buffer,sizeof(buffer),f); // Se almacena la línea del archivo en buffer
      sscanf(buffer, "%f,%f,%f,%f,%f", &u, &v, &vis[0], &vis[1], &vis[2]); // coordX, coordY, parte real, parte imaginaria, ruido
      int Ndisco = getIndexProccess(n,discWidth,originDistance(u,v)); // se obtiene el disco al que pertenece el punto
      arrayMaster[Ndisco][0] += vis[0]; // Se realiza la suma de la parte real del punto al disco correspondiente
      arrayMaster[Ndisco][1] += vis[1]; // Se realiza la suma de la parte imaginaria del punto al disco correspondiente
      arrayMaster[Ndisco][2] += sqrt(pow(vis[0], 2) + pow(vis[1], 2));  // Se realiza la suma y cálculo de la potencia del punto al disco correspondiente
      arrayMaster[Ndisco][3] += vis[2]; // Se realiza la suma del ruido del punto al disco correspondiente
      arrayMaster[Ndisco][4] += 1;  // Acumulador de puntos al disco correspondiente
      // printf("Thread %ld: Disco %d, coordenadas (%f,%f), parte real %f, parte imaginaria %f, ruido %f\n", *myID, Ndisco, u, v, vis[0], vis[1], vis[2]); // impresión de los datos del punto leido
		}
    pthread_mutex_unlock(&mutex); // Se sale de la sección crítica
    // printf("HEBRA ID %ld\n",*myId);  // Se imprime para verificar la concurrencia
  }
}

int main(int argc, char *argv[]) {
  char *inputFile = NULL, *outputFile = NULL;
  while ((option = getopt(argc, argv, "i:o:n:d:h:c:b")) != -1) {
    switch (option) {
      case 'i':  // Nombre del archivo de entrada
        inputFile = optarg;
        break;
      case 'o':  // Nombre del archivo de salida
        outputFile = optarg;
        break;
      case 'n':  // Numero de discos
        sscanf(optarg, "%d", &n);
        break;
      case 'd':  // Ancho de cada disco
        sscanf(optarg, "%d", &discWidth);
        break;
      case 'h':  // Cantidad de hebras
        sscanf(optarg, "%d", &threads);
        break;
      case 'c':  // Numero de líneas que la hebra lee por vez
        sscanf(optarg, "%d", &chunk);
        break;
      case 'b':  // Flag para indicar que se debe imprimir las propiedades por consola
        b = 1;
        break;
      case '?': // Opcion invalida
        exit(0);
      default:  // En caso que no se haya ingresado alguna flag obligatoria, se aborta la ejecucion
        abort();
    }
  }
  // Verificaciones
  if (n <= 0) { // Si el numero de discos es menor o igual a 0
    printf("numero de discos inválido\n");
    return 0;
  }
  if (threads <= 0) { // Si el numero de hebras es menor o igual a 0
    printf("Cantidad hebras invalida\n");
    return 0;
  }
  if (chunk <= 0) { // Si el numero de líneas a leer por hebra es menor o igual a 0
    printf("chunk invalido\n");
    return 0;
  }
  if (discWidth <= 0) { // si el ancho de cada disco es menor o igual a 0
    printf("ancho de disco invalido\n");
    return 0;
  }
  f = fopen(inputFile, "r");  // Se abre el archivo de entrada en modo lectura
  if (f == NULL) {  // Si el archivo no existe.
    printf("No se pudo abrir archivo\n"); // Se imprime mensaje de error
    exit(0);  // Se termina la ejecución
  }
  arrayMaster = (float **)malloc(n * sizeof(float *));  // Se reserva memoria para arrayMaster
  for (int i = 0; i < n; i++) {
    arrayMaster[i] = (float *)malloc(5 * sizeof(float));  // Se reserva memoria para cada disco
  }
  pthread_t threadsArray[threads];  // Se reserva memoria para el arreglo de hebras
  for (int tid = 0; tid < threads; tid++) { // Se crean las hebras
    pthread_create(&threadsArray[tid], NULL, hebras, (void *)&threadsArray[tid]);
  }
  for(int tid = 0; tid < threads;tid++){  // Se espera que cada hebra termine de ejecutarse
    pthread_join(threadsArray[tid], NULL);
  }
  for(int i = 0; i < n; i++){  // Se calcula la media real y media imaginaria de cada disco
    for(int j = 0; j < 2; j++){
      arrayMaster[i][j] = arrayMaster[i][j]/arrayMaster[i][4];  // media = suma/cantidad de puntos
    }
  }
  if(b == 1){ // Si se activa la flag b
    imprimirProps(n,arrayMaster); // Se imprime las propiedades por consola
  }
  escribirSalida(n, outputFile, arrayMaster); // Se escribe el archivo de salida
}