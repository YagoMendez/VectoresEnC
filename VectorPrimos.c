#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include<time.h>
#define p printf
#define sc scanf
#define ancho 20

void cargarVector(int[]);
void comparar(int[], int[], int*);
void sort(int[], int*);

int main(){
    int vec[ancho], vecPrimos[ancho], nPrim = 0;

    srand(time(NULL));
    cargarVector(vec);
    comparar(vec, vecPrimos, &nPrim);
    sort(vecPrimos, &nPrim);


    return 0;
}

void cargarVector(int vec[ancho]){
    for(int i = 0; i < ancho; i++){
        vec[i] = rand() % (200 - 1 + 1) + 1;
    }
    p("VECTOR ORIGINAL:\n");
    for(int i = 0; i < ancho; i++){
        p("%d)\t%d\n", i+1, vec[i]);
    }
}

void comparar (int vec[], int vecPrimos[], int *nPrim){
    

    for(int i = 0; i < ancho; i++){
        int flag = 1;
        for (int j = 2; j <= vec[i]/2; j++){
            if (vec[i] % j  == 0){
                flag = 0;
                break;
            }
        }
        if(flag && vec[i] != 1){
            vecPrimos[*nPrim] = vec[i];
            (*nPrim)++;
        }
    }
    p("Numeros Primos: %d\n", *nPrim);
    
}
void sort(int primos[], int *nPrim){
    int aux;
    p("Vector Primos sin Ordenar:\n");
    for (int i = 0; i < *nPrim; i++){
        p("%d)\t%d\n", i+1, primos[i]);
    }
    for (int i = 0;i < *nPrim; i++){
        for(int j = i+1; j <= *nPrim; j++){
            if (primos[i] > primos[j]){
                aux = primos[i];
                primos[i] = primos[j];
                primos[j] = aux;
            }
        }
    }
    p("NUMEROS PRIMOS ORDENADOS:\n");
    for(int i = 0; i < *nPrim; i++){
        p("%d)\t%d\n", i+1, primos[i]);
    }
}