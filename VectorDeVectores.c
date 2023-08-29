#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include<time.h>
#define p printf
#define sc scanf
#define ancho 10
/*Array de punteros que contenga 3 vectores con 10 posiciones
Paso 1: obtener las direcciones de los vector con  funcion
Paso 2:Funcion cargar con srand 20/500
Paso 3: funcion listar*/

void direccion(int**, int*, int*, int*);
void cargar(int**, int);
void listar(int**, int*, int*, int*);

int main(){
    int vec[ancho], vec1[ancho], vec2[ancho], *array[3] = {NULL};
    srand(time(NULL));
    direccion(array, vec, vec1, vec2);
    for(int i = 0; i < 3; i++){
        cargar(array[i],10);
    }
    listar(array, vec, vec1, vec2);
    return 0;
}
void direccion (int **array, int vec[], int vec1[], int vec2[]){
    array[0] = vec;
    array[1] = vec1;
    array[2] = vec2;
}
void cargar(int **array, int tam){
    
    for (int j = 0; j < tam; j++){
        *(array + j) = rand() % (500 - 20  + 1) + 20;
    }
}
void listar(int **array, int vec[], int vec1[], int vec2[]){
    for (int i = 0; i < 3; i++){
        p("\nVector %d:\n", i+1);
        for (int j = 0; j < 10; j++){
         p("|   %d     |   ", *(array[i]+j));   
        }
    }  
}