#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#define p printf
#define sc scanf
#define ancho 50
/*Escribe un programa que llene un vector de 50 elementos con los números de Fibonacci. Los
primeros números son 1, 1, 2, 3, 5 (cada número es la suma de los dos anteriores). Emite el
contenido del vector por pantalla.*/

int main(){
    float fibonacci[ancho], previo = 0, actual = 1;
    fibonacci[0] = 1;

    for(int i = 0; i < ancho; i++){
         
        fibonacci[i] = actual + previo;
        previo = actual;
        actual = fibonacci[i];
    }
    for(int i = 0; i < ancho; i++){
       p("%d)\t%.f\n", i+1, fibonacci[i]);
    }

    return 0;
}