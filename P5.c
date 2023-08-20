#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#define p printf
#define sc scanf
#define ancho 11

/*Escribe un programa que, a partir de un vector vacío de enteros, permita insertar nuevos
números en posiciones válidas del mismo. El programa emitirá repetidamente al usuario un
menú con cuatro opciones:
a) Insertar delante: Esta opción agrega un número en la primera posición del vector. Deberá
desplazar, si fuese necesario, el resto de los elementos una posición a la derecha. Si el vector
estuviese lleno, se perdería su último elemento.
b) Insertar detrás: agrega un nuevo elemento al final del vector, es decir, en la última celda. Si
el vector estuviese lleno, el elemento se inserta en la última celda del vector y se perdería el
elemento que estaba allí anteriormente.
c) Insertar en una posición dada: Dado un índice del vector, se debe insertar un nuevo
elemento en dicha posición, siempre que el nuevo elemento sea contiguo a los ya existentes.
Por ejemplo, si en el vector hay tres elementos (que ocupan las posiciones 0, 1 y 2) no se
permite agregar un elemento en la posición 7 porque no forma una secuencia continua, pero
sí se permite en la posición 3. Por otra parte, si la posición dada está ocupada, los elementos
se deben desplazar una posición a la derecha y, si el vector estaba lleno, se pierde el último
elemento.
d) Finalizar el programa.
*/

int menu ();
void adelante (int[]);
void atras (int[]);
void posicionDefinida(int[]);

int main(){
    int n[ancho], op;
    
    do{
        op = menu();
        
        if (op == 0){
            p("\nADIOS!\n");
            sleep(2);
            system("pause");
            system("cls");
            break;
        }else{
            switch(op){
            case 1:
                adelante(n);
                break; 
            case 2:
                atras(n);
                break;  
            case 3:
                posicionDefinida(n);
                break;         
            }  
        }
    }while(op != 0); 
    

    return 0;
}
int menu(){
    int opcion;

    do{
        system("cls");
        p("BIENVENIDO!\n");
        p("\n1)\tINSERTAR EN LA PRIMERA POSICION\n");
        p("2)\tINSERTAR EN LA ULTIMA POSICION\n");
        p("3)\tINSERTAR EN UNA POSICION DEFINIDA\n");
        p("0)\tSALIR\n");
        sc("%d", &opcion);

        if(opcion != 1 && opcion != 2 && opcion != 3 && opcion != 0){
            p("Opcion incorrecta, reintentelo\n");
        }
    }while(opcion != 1 && opcion != 2 && opcion != 3 && opcion != 0);

    return opcion;
}
void adelante (int x[]){
    int aux;

    for(int i = 0; i < ancho; i++){
        for(int j = i+1; j <= ancho; j++){
            aux = x[j];
            x[j] = x[i];
            x[i] = aux;
        }
    }
    p("INGRESE UN VALOR:\n");
    sc("%d", &x[0]);
    
    for(int i = 1; i < ancho; i++){
        for(int j = i+1; j <= ancho; j++){
            aux = x[j];
            x[j] = x[i];
            x[i] = aux;
        }
    }

    for (int i = 0; i < ancho; i++){
        p("%d)\t%d\n", i+1, x[i]);
    }
    system("pause");
}
void atras (int x[]){

    p("INGRESE UN VALOR:\n");
    sc("%d", &x[10]);
    
    for (int i = 0; i < ancho; i++){
        p("%d)\t%d\n", i+1, x[i]);
    }
    system("pause");

}
void posicionDefinida (int x[]){
    int pos;
    do{
        p("INGRESE LA POSICION EN LA CUAL DESEA GUARDAR EL VALOR:\n");
        sc("%d", &pos);
       
        if(pos > 11){
        p("El vector tiene 11 posiciones, reintentelo\n");
        }
    }while(pos > 11);
    
    p("INGRESE UN VALOR:\n");
    sc("%d", &x[pos-1]);

    for (int i = 0; i < ancho; i++){
        p("%d)\t%d\n", i+1, x[i]);
    }
    system("pause");   
}
