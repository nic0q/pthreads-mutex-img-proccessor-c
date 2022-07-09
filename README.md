# Laboratorio 2 Sistemas Operativos 2022-1
Este laboratorio consiste en la elaboración de un programa que permite leer un archivo de texto y calcular una serie de propiedades utilizando funciones
de la biblioteca pthread, guardando el resultado en otro archivo de texto. 
* Para una explicación completa revise el [enunciado de laboratorio](https://github.com/nic0q/LAB2-SISTOPE/blob/master/laboratorio_2_SO_1_2022.pdf).

## Significado Flags:
- -i: Nombre del archivo de entrada con las visibilidades
- -o: Nombre del archivo de salida
- -n: Número de discos a crear
- -d: Ancho de disco (unidades)
- -h: Número de hebras a crear
- -c: Chunk que cada hebra leerá
- -b: Si esta activa, se muestra por consola los resultados de los cálculos de las propiedades.

## Instrucciones
Se recomienda clonar el repositorio:
```sh
git clone https://github.com/nic0q/LAB2-SISTOPE
```
Ejecutar de la siguiente forma: (**En el repositorio se dispone de test100.csv y test1000.csv**)
- Compilar con el makefile **make**
- Ejecutando un test con **make run**
- Ejecutando otro test con **make run100**
- Ejecutando otro test con **make runSilent**
- Manualmente con: ./lab2 -i test1000.csv -o propiedades.txt -n 4 -d 200 -h 5 -c 3 -b

## Realizado por
[John](https://github.com/PodssilDev)<br/>
[Nícolas](https://github.com/nic0q)<br/>
