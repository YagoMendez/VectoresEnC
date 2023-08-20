#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#define sc scanf
#define p printf
#define ancho 10

/*2. Escribe un programa con un menú que defina las siguientes funciones y emita los resultados, la
dimensión del vector será de 10 (elementos):
a) Cargar m elementos de un vector por teclado. Deberá considerar que no podrá superar el
máximo de elementos de vector: void cargar(int vect[], int unNum);
b) Leer elementos de un vector hasta encontrar el número entero a. Deberá retornar el
número de elementos que ha leído sin contar el entero a. int leerMarca(int
vect[]);
c) Dado un elemento y dado un vector de enteros, desarrolle una función que devuelva el
número de apariciones del elemento en el vector. int veces(int valor, int
vect[], int unNum);
d) Invertir los elementos del vector sin utilizar otro vector. Por ejemplo, el vector formado por
los enteros: 1 2 3, debe quedar 3 2 1. void invertirOrden(int vect[], int
unNum);
*/
/*PUNTO 3: a) Calcular y emitir la suma de sus elementos.
b) Calcular y emitir el mínimo del vector.
c) Calcular y emitir el promedio de los valores del vector
d) Emitir los valores de aquellos que superaron ese promedio.
e) Emitir los valores del vector que son múltiplos del último número ingresado en el mismo.
f) Emitir el valor máximo e indicar la cantidad de veces que apareció y el número de orden en
que fue ingresado.
g) Emitir los valores que son pares.
h) Emitir los valores que son impares.
i) Emitir aquellos que estén ubicados en posición par.
*/

int menu ();
int cargar(int[]);
int lector (int[]);
int repeticion (int, int[], int);
void inversor (int[], int);
void sumar (int[]);
void minYmax(int[]);
void prom(int[]);
void mul(int[]);

int main(){
    int n[ancho], numero=0, valor=0, op;
    system("cls");
    p("BIENVENIDO!, ELIJA LA OPCION A LLEVAR A CABO:\n");
    do{
        
        op = menu();// lo primero que hago es correr la funcion menu y le asigno su devolucion a la variable op

        if (op != 0){
            
            switch (op){//corremos el switch basado en op que a su vez es la funcion menu
                case 1:
                    n[ancho] = cargar(n);// asignamos la carga a la funcion, unico paso realmente necesario para que funcionen los otros
                    break;
                case 2:
                    lector(n);
                    system("pause");
                    break;
                case 3:
                    repeticion(valor, n, numero); 
                    system("pause"); 
                    break;
                case 4:
                    inversor(n, numero);
                    system("pause");
                    break;
                case 5:
                    sumar (n);
                    break;
                case 6:
                    minYmax(n);
                    break; 
                case 7:
                    prom(n);
                    break;
                case 8:
                    mul(n);
                    break;       

            }
        }else{
            system("cls");
            p("Adios!\n");
            sleep(2);
            system("cls");
        }
            

        
    }while(op != 0);

    return 0;
}

int menu (){
    int x;

    do{
        p("1) CARGAR VECTOR\n");
        p("2) RECORRER EL VECTOR\n");
        p("3) ANALIZAR REPETICIONES\n");
        p("4) INVERTIR ELEMENTOS DEL VECTOR\n");
        p("5) SUMAR LOS ELEMENTOS DEL VECTOR\n");
        p("6) ENCONTRAR EL MINIMO INGRESADO\n");
        p("7) SACAR EL PROMEDIO DEL VECTOR Y ANALIZAR SI ALGUN ELEMENTO LO EXCEDE\n");
        p("8) ANALIZAR SI ALGUN ELEMENTO ES MULTIPLO DEL ULTIMO INGRESADO\n");
        p("0) SALIR\n");
        sc("%d", &x);
    }while (x != 1 && x != 2 && x != 3 && x != 4 && x != 0 && x != 5 && x != 6 && x !=7 && x != 8);// vuelta eterna a la funcion menu
    
    return x;
}
int cargar (int x[ancho]){
    getchar;
    for(int i = 0; i < ancho; i++){
        p("Ingrese el %d Valor:\n", i+1);
        sc("%d", &x[i]);
    }
    return x;
}
int lector (int x[ancho]){
    p("Procederemos a leer el Vector:\n");
    sleep(1);
    
    for(int i = 0; i < ancho; i++){
        int a = 23;// aca sarasee porque no se entendia la consigna, no me hice mucho dram y asigne arbitrariamente

        p("%d)\t%d\n", i+1, x[i]);
        
        if(x[i]== a){
            p("Se leyeron %d numeros hasta llegar al indicado\n", i);
            break;
        }
    }
}
int repeticion (int y, int x[ancho], int z){
    p("Ingrese un valor para analizar si existe en el vector y si se repitio:\n");
    sc("%d", &z);// ingreso un valor para buscarlo en el vector

    for (int i = 0; i < ancho; i++){
        if(x[i] == z){
            p("Posicion: %d)\t%d\n", i+1, x[i]);
            y++;// "y" es en realidad un contador de repeticiones
        }
    }
    p("Repeticiones de %d:\t%d\n", z, y);

}
void inversor (int x[ancho], int y){// no estoy seguro de si eesta funcion anda bien, no la volvi a probar
    int aux = 0;
    p("Vector original:\n");

    for(int i = 0; i < ancho; i++){
        p("%d)\t%d\n", i+1, x[i]);
    }
    p("\n---------------------------------------------------------------------\n");
    p("\nVector invertido:\n");
    
    for(int j = 0; j < ancho; j++){

        for (int z = j+1; z <= ancho; z++){
            aux = x[j];
            x[j]= x[z];
            x[z] = aux;
        }
        
    }
}

void sumar (int x[ancho]){// suma de los elementos, facilito
    int acum = 0;
    for(int i = 0; i < ancho; i++){
        acum+= x[i];
    }
    p("LA SUMA DE LOS ELEMENTOS ES: %d\n", acum);
}
void minYmax (int x[ancho]){// reordenamiento del vector, maximos y minimos
    int acumMenor=0, acumMayor=0, repe[ancho];
      
    for (int i = 0; i < ancho; i++){
       
        for(int j = i+1; j < ancho ; j++){
        int aux;

            if(x[j] < x[i]){
                aux = x[j];
                x[j]= x[i];
                x[i] = aux;
            } 
        }

    }
    p("VECTOR REORDENADO DE MENOR A MAYOR:\n");

    for(int z = 0; z < ancho; z++){
        p("%d)\t%d\n", z+1, x[z]);
    }
    p("MENOR INGRESADO: %d\n", x[0]);
    p("MAYOR INGRESADO: %d\n", x[9]);

    for(int i = 1; i < 9; i++){
        if(x[i] == x[0]){
            acumMenor+=1;// calaramente acums
            p("POSICION MENOR: %d\n", i+1);
        }
        if(x[i] == x[9]){
            acumMayor+=1;
            p("POSICION MAYOR: %d\n", i+1);
        }
    }
    p("CANTIDAD DE REPETICIONES DEL MAYOR: %d\n", acumMayor);
    p("CANTIDAD DE REPETICIONES DEL MENOR: %d\n", acumMenor);
    system("PAUSE");
}
void prom (int x[ancho]){
    int acum, op;

    for(int i = 0; i < ancho; i++){
        acum+= x[i];
    }
    p("EL PROMEDIO DE LOS ELEMENTOS ES: %d\n", acum/10);
    p("QUIERE ANALIZAR SI ALGUN ELEMENTO LO EXCEDE?(1/2)\n");// otra consigna medio chota, no se si era lo que pedian
    sc("%d", &op);

    if(op == 1){
        p("VALORES QUE CUMPLEN LA CONDICION:\n");
        for(int i = 0; i < ancho; i++){
            if(x[i] > (acum/10)){
                p("POSICION:%d)\t%d\n", i+1, x[i]);
            }
        }
        system("PAUSE");
    }else 
    system("PAUSE");
}
void mul(int x[ancho]){
    int op;
    for(int z = 0; z < 9; z++){
       if(x[z] % x[9] == 0){
            p("%d es multiplo de %d\n", x[z], x[9]);// los santos multiplos del ultimo num ingresado
        }
    }
    p("DESEA IMPRIMIR TODOS LOS PARES?(1/2)\n");
    sc("%d", &op);

    if(op == 1){
        p("NUMEROS PARES:\n");
        for(int w = 0; w < ancho; w++){
            if(x[w] % 2 == 0){
                p("%d\n", x[w]);
            }
        }
        p("NUMEROS IMPARES:\n");
        for(int h = 0; h < ancho; h++){
            if(x[h] % 2 != 0){
                p("%d\n", x[h]);
            }
        }
        p("NUMEROS EN POSICION PAR:\n");// analisis de posicion par, facilito pero capaz no es lo primero que se te ocurre

    for(int c = 0; c < ancho; c++){
        if((c+1) % 2 == 0){
            p("%d\n", x[c]);
        }
    }
    }
}