#include "funciones.h"
// I: numero de discos, array a imprimir
// O: void
void imprimirProps(int n, float**arrayMaster) {
  for(int i = 0;i < n;i++){
    printf("Disco: %d\n n°Visibilidades: %f\n mediaR: %f\n mediaI: %f\n potenciaT: %f\n ruidoT: %f\n",i+1,arrayMaster[i][4],arrayMaster[i][0],arrayMaster[i][1],arrayMaster[i][2],arrayMaster[i][3]);
  }
}
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
float originDistance(float u, float v) { return sqrt(pow(u, 2) + pow(v, 2)); }