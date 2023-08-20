#include<stdio.h>
#include<stdlib.h>
#define sc scanf
#define p printf
#define ancho 10
/*Construye un programa, utilizando funciones, que lea como máximo 10 números enteros, el
ciclo termina al introducir un cero. A continuación, lea otro entero y compruebe si ese entero
está o no entre los anteriores. En caso de que se encuentre, contar y emitir el número de veces
que aparece.*/

void cargar(int[]);
void check(int[]);

int main(){
    int vector[ancho], continuar;

    do{
        cargar(vector);

        do{
            check(vector);

            do{
                p("Quiere\t1)Buscar un valor\t2)Cargar otro Vector\t3)Salir?\n");
                sc("%d", &continuar);
                if(continuar != 1 && continuar != 2 && continuar != 3){
                    p("OPCION INCORRECTA, INGRESE 1, 2 O 3\n");
                }

            }while(continuar != 1 && continuar != 2 && continuar != 3);
            
        }while(continuar == 1);

        if(continuar == 3){
            p("Adios!\n");
        }
    }while(continuar == 2);
  
    return 0;
}
void cargar(int x[]){
    system("cls");
    p("BIENVENIDO!\n");

    for(int i = 0; i < ancho; i++){
        p("Ingrese el %d valor (de %d) o presione 0 para cortar la carga:\n", i+1, ancho - i);
        sc("%d", &x[i]);
        if(x[i] == 0){
            break;
        }
    }
}
void check(int x[]){
    int cobani, acum = 0;
    p("Ingrese el valor que quiere encontrar en el Vector:\n");
    sc("%d", &cobani);

    for(int i = 0; i < ancho; i++){
        if(x[i] == cobani){
            acum+=1;
        }
    }
    p("%d se repite %d veces\n", cobani, acum);
    system("PAUSE");
}