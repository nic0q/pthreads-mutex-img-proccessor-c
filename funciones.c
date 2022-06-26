#include "funciones.h"

// Entrada: Un entero correspondiente al numero de discos y un array a imprimir
// Salida: No tiene salida como tal (Pero imprime en terminal)
// Descripcion: Funcon que imprime por consola el resultado del calculo de las propiedades de cada disco
void imprimirProps(int n, float**arrayMaster) {
  for(int i = 0;i < n;i++){
    printf("Disco: %d\n n°Visibilidades: %f\n mediaR: %f\n mediaI: %f\n potenciaT: %f\n ruidoT: %f\n",i+1,arrayMaster[i][4],arrayMaster[i][0],arrayMaster[i][1],arrayMaster[i][2],arrayMaster[i][3]);
  }
}

// Entrada: Dos numeros enteros, el primero la cantidad de procesos, el segundo el ancho de discos
// y un flotante, el cual es la distancia que tiene un punto al origen
// Salida: Un entero, correspondiente a que numero de disco pertenece el punto de visibilidad
// Descripcion: Funcion que a traves de la distancia de la visibilidad al origen, determina
// a que disco pertenece la visibilidad 
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

// Entrada: Dos numeros flotantes, correspondientes a las coordenadas (u,v) de la visibilidad
// Salida: Un flotante, correspondiente a la distancia de la coordenada al origen (0,0)
// Descripcion: Funcion que calcula la distancia que hay entre unas coordenadas (u,v) al origen (0,0) en un plano
float originDistance(float u, float v) { return sqrt(pow(u, 2) + pow(v, 2)); }

// Entrada: Un entero, el cual es el numero de discos, un caracter a puntero el cual es el
// nombre del archivo de salida y un arreglo de arreglos de flontates, que contiene todos 
// los resultados de los calculos hechos por los hijos en un solo arreglo
// Salida: Como tal no tiene salida, pero crea y escribe el archivo de salida
// Descripcion: Funcion que crea y escribe el archivo de salida, colocando la informacion
// de las propiedades asociadas a todos los discos.
void escribirSalida(int nProcesses, char *outputFile, float** datos) {
  FILE *salida = fopen(outputFile, "w");
  for (int i = 0; i < nProcesses; i++){
    if (i != 0){fprintf(salida, "\n");}
      fprintf(salida, "Disco %i:\nMedia real: %f\nMedia imaginaria: %f\nPotencia: %f\nRuido total: %f",
      i + 1,datos[i][0],datos[i][1],datos[i][2],datos[i][3]);
  }
  fclose(salida);
}
