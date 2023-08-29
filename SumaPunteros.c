#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include<time.h>
#define p printf
#define sc scanf

int suma (int, int, int *);

int main(){
    int a, b, resultado, *ptr;

    *ptr = &resultado;
    system("cls");
    p("Ingrese el primer valor:\n");
    sc("%d", &a);
    p("Ingrese el segundo valor:\n");
    sc("%d", &b);

    suma(a, b, ptr);

    p("El resultado de la suma de %d + %d es = %d", a, b, *ptr);

    return 0;
}

int suma(int a, int b, int *ptr){
    *ptr = a + b;

    return *ptr;
}