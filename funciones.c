#include "funciones.h"

FILE* f;  // Descriptor global

float originDistance(float u, float v) { return sqrt(pow(u, 2) + pow(v, 2)); }

void openFile(char* name) {
  f = fopen(name, "r");  // Se abre el archivo
  // printf("%d %d %d hola", numeroDiscos , anchoDiscos , chunksPorLeer);
  if (f == NULL) {  // Si el archivo no existe.
    printf("No se pudo abrir archivo\n");
    exit(0);
  }
}
void readFile(int nLines) {
  char buffer[1000];
  float u, v, vis[3];
  int cont = 0;
  while (fgets(buffer, 1000, f) != NULL) {
    sscanf(buffer, "%f,%f,%f,%f,%f", &u, &v, &vis[0], &vis[1], &vis[2]);
    float oDistance = originDistance(u, v);  // Se calcula la distancia de la visibilidad al origen
    int index = getIndexProccess(numeroDiscos, anchoDiscos, oDistance);  // Se determina a que disco pertenece la visibilidad
    if(cont == nLines){
      return;
    }
    cont++;
  }
}

void* trabajoHebras() {
  while (1 == 1) {
    pthread_mutex_lock(mutex);  // esto nos bloquea la SC
    
  }
}
// 2 discos , arreglo de 2 posiciones. Y cada posicion es sub arreglo que tiene
// las sumas importantes
