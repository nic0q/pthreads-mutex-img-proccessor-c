#include "funciones.h"

FILE* f;  // Descriptor global

float originDistance(float u, float v) { return sqrt(pow(u, 2) + pow(v, 2)); }

int getIndexProccess(int numeroDiscos, int anchoDiscos, float oDistance) {
  int j = anchoDiscos;
  if(oDistance >= (numeroDiscos - 1) * anchoDiscos) {
    return numeroDiscos - 1;
  }
  else{
    for(int i = 0;i < numeroDiscos;i++) {
      if(i * anchoDiscos <= oDistance && oDistance < j){
        return i;
      }
      j = j + anchoDiscos;
    }
  }
}

void openFile(char* name) {
  f = fopen(name, "r");  // Se abre el archivo
  // printf("%d %d %d hola", numeroDiscos , anchoDiscos , chunksPorLeer);
  if (f == NULL) {  // Si el archivo no existe.
    printf("No se pudo abrir archivo\n");
    exit(0);
  }
}
void readFile() {
  char buffer[1000];
  float u, v, vis[chunksPorLeer][4];
  int disco_actual;
  int cont = 0;
  while (fgets(buffer, 1000, f) != NULL) {
    sscanf(buffer, "%f,%f,%f,%f,%f", &u, &v, &vis[cont][1], &vis[cont][2], &vis[cont][3]);
    float oDistance = originDistance(u, v);  // Se calcula la distancia de la visibilidad al origen
    int index = getIndexProccess(numeroDiscos, anchoDiscos, oDistance);  // Se determina a que disco pertenece la visibilidad
    vis[cont][0] = index;
    // printf("%i: %d y %f\n",cantidadde_lineas, index, vis[cont][3]);
    cantidadde_lineas++;
    if(cont == chunksPorLeer){
      break;
    }
    cont++;
  }
  for(int i = 0; i < 4; i++){
    disco_actual = vis[i][0];
    masterArray[disco_actual][0] += vis[i][1];
    masterArray[disco_actual][1] += vis[i][2];
    masterArray[disco_actual][2] += vis[i][3];
  }
}

void* trabajoHebras() {
  int cont = 0;
  while (1 == 1) {
    pthread_mutex_lock(&mutex);  // esto nos bloquea la SC
    cont += 1;
    if(cont == 101){
      pthread_mutex_unlock(&mutex);
      printf("%i\n", 9);
      pthread_exit(NULL);
    }
    readFile();
    pthread_mutex_unlock(&mutex);
  }
}
// 2 discos , arreglo de 2 posiciones. Y cada posicion es sub arreglo que tiene
// las sumas importantes
