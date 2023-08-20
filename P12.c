#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#define p printf
#define sc scanf


/*Dado un vector de dimensión N y un valor x float, desarrollar una función que almacene x en la
posición i de un vector. Los valores no se ingresan ordenados por posición, se debe ingresar la
posición y el valor de x hasta completar el vector. Al finalizar, emitir el contenido del vector
indicando la posición ocupada por cada número a partir de la primera posición. Se debe utilizar
funciones.*/

int carga(int, float[]);
void mostrar(int, float[]);

int main (){
    int ancho;
    float vector[ancho];

    do{
        //system("cls");
        p("Bienvenido!, Seleccione el ancho del Vector o presione 0 para salir:\n");
        sc("%d", &ancho);
        carga(ancho, vector);
        mostrar(ancho, vector);
    }while(ancho != 1);
}
int carga(int ancho, float vec[ancho]){
    int posicion;
    for(int i = 0; i < ancho; i++){
        do{
            p("En que posicion desea almacenar el dato?:\n");
            sc("%d", &posicion);
            p("Ingrese el dato %d de %d:\n", i+1, ancho);
            sc("%f", &vec[posicion]);
        }while(i < ancho);
    }
}
void mostrar(int ancho, float vec[ancho]){
    p("El vector quedo de la siguiente manera:\n");
    for(int i = 0; i < ancho; i++){
        p("%d)\t\t%2.f", i+1, vec[i]);
    }
}