#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include<time.h>
#define p printf
#define sc scanf

int intercambio(int *, int *);

int main(){
    int a, b, *ptr, *ptr1;


    p("Ingrese el valor A:\n");
    sc("%d", &a);
    p("Ingrese el valor B:\n");
    sc("%d", &b);

    ptr = &a;
    ptr1 = &b;
    
    p("PTR: %d\n", *ptr);
    p("PTR1: %d\n", *ptr1);

    intercambio(ptr, ptr1);

    p("POST INTERCAMBIO:\n");
    p("A: %d\n", a);
    p("B: %d\n", b);
    p("PTR: %d\n", *ptr);
    p("PTR1: %d\n", *ptr1);
    return 0;
}

int intercambio(int *a, int *b){
    int *aux;

    aux = *a;
    *a = *b;
    *b = aux;

    return *a, *b;
}