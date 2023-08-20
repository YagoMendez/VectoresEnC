#include<stdio.h>
#include<stdlib.h>
#define sc scanf
#define p printf
#define ancho 5

/*Desarrolle una función que reciba un vector de 10 números enteros y muestre los valores por
pantalla, eliminando las repeticiones.
*/
int cargarVec(int[]);
int mostraryCotejar(int[]);

int main(){
    int vector[ancho];

    cargarVec(vector);
    mostraryCotejar(vector);
    return 0;
}

int cargarVec(int x[]){
    p("Bienvenido!\n");
    
    for(int i = 0; i < ancho; i++){
        p("Ingrese el %d valor:\n", i+1);
        sc("%d", &x[i]);
    }
    
    return x;
}
int mostraryCotejar(int x[]){
    int repe[ancho], repe2[ancho];
    for(int i=0; i < ancho; i++){
        for (int j = i+1; j <= ancho; j++){
            if(x[i] == x[j]){
                repe[i] = i;
            }
            if(x[i] == x[j+1]){
                repe2[i] = i;
            }
        }
    }
    for (int i = 0; i < ancho; i++){
        if(repe[i] == i || repe2[i] == i){
            p("%d)\tACA HABIA UNA REPETICION: %d\n", i+1, x[i]);
        }else
            p("%d)\t%d\n", i+1, x[i]);
    }
}