#include "funciones.h"

// Entrada: Un entero correspondiente al numero de discos y un array a imprimir
// Salida: No tiene salida como tal (Pero imprime en terminal)
// Descripcion: Funcon que imprime por consola el resultado del calculo de las propiedades de cada disco
void imprimirProps(int n, float**array) {
  for(int i = 0;i < n;i++){
    int nVis = (int)array[i][4];
    printf("Disco: %d\n N°Visibilidades Proc: %d\n Media real: %f\n Media Imaginaria: %f\n Potencia Total: %f\n Ruido Total: %f\n",i+1,nVis,array[i][0],array[i][1],array[i][2],array[i][3]);
  }
}

// Entrada: Dos numeros enteros, el primero la cantidad de procesos, el segundo el ancho de discos
// y un flotante, el cual es la distancia que tiene un punto al origen
// Salida: Un entero, correspondiente a que numero de disco pertenece el punto de visibilidad
// Descripcion: Funcion que a traves de la distancia de la visibilidad al origen, determina
// a que disco pertenece la visibilidad 
int getIndexProccess(int nDisks, int diskWidth, float oDistance) {
  int j = diskWidth;
  if(oDistance >= (nDisks - 1) * diskWidth) {
    return nDisks - 1;
  }
  else{
    for(int i = 0; i < nDisks; i++) {
      if(i * diskWidth <= oDistance && oDistance < j){
        return i;
      }
      j = j + diskWidth;
    }
  }
}

// Entrada: Dos numeros flotantes, correspondientes a las coordenadas (u,v) de la visibilidad
// Salida: Un flotante, correspondiente a la distancia de la coordenada al origen (0,0)
// Descripcion: Funcion que calcula la distancia que hay entre unas coordenadas (u,v) al origen (0,0) en un plano
float originDistance(float u, float v) {
  return sqrt(pow(u, 2) + pow(v, 2));
}

// Entrada: Un entero el numero de discos, un caracter a puntero el
// nombre del archivo de salida y un arreglo de arreglos de flontates, que contiene todos 
// los resultados de los calculos hechos por los hijos en un solo arreglo
// Salida: Como tal no tiene salida, pero crea y escribe el archivo de salida
// Descripcion: Funcion que crea y escribe el archivo de salida, colocando la informacion
// de las propiedades asociadas a todos los discos.
void escribirSalida(int nProcesses, char *nameOutputFile, float** datos) {
  FILE *salida = fopen(nameOutputFile, "w");
  for (int i = 0; i < nProcesses; i++){
    if (i != 0){fprintf(salida, "\n");}
      fprintf(salida, "Disco %i:\nMedia real: %f\nMedia imaginaria: %f\nPotencia: %f\nRuido total: %f",
      i + 1,datos[i][0],datos[i][1],datos[i][2],datos[i][3]);
  }
  fclose(salida);
}