#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#define sc scanf
#define p printf
#define quini 10

/*Escribe un programa que almacene, en un vector con dimensión 10, los números 10 primeros
números de la Quiniela. El ingreso de los datos será indicando posición-numero, de modo que
puedo ingresar la posición 5 antes que la posición 2*/

int kini (int[]);

int main(){
    
    int n[quini], conti;

   do{ 
        system("CLS");
        p("\nBienvenido al almacenador de los ganadores del Quini!\n");
       
       kini(n); /*funcion para el ingreso del vector, le paso "n" con numero de posicion definido, 
                 ya que no se puede pasar un numero de lugares a la funcion*/
        p("Los ganadores son:\n");

        for(int i = 0; i < 10; i++){    //print del Vector
            p("%d)\t%d\n", i+1, n[i]);  //en orden: numero de vuelta, numero en posicion i
        }
        do{ //loop para el loop, t/f
            p("PRESIONE 1 PARA CONTINUAR Y 2 PARA SALIR:\n");
            sc("%d", &conti);
            if (conti != 1 && conti != 2){
                p("PRESIONE 1 O 2 DIJE CARAJO\n");
            }else if (conti == 2){
                p("Adios!\n");
            }
        }while(conti != 1 && conti != 2);
   }while(conti != 2);  //cierre del programa 
   system("pause");
   system("cls");

   return 0;

}

int kini(int x[quini]){
    int posicion, vuelta = 0, valid[9], flag = 0;

    do{ //loop con conteo de vueltas predefinido
        do{
            do{
                p("Ingrese el orden del valor a ingresar(%d/10):\n", vuelta+1);
                sc("%d", &posicion); // pido la posicion del Vector para que se pueda ingresar en cualquier orden
                if (posicion > 10){
                    p("Se permiten ingresar solo los 10 primeros numeros, reintentelo\n");
                }

                for (int i = 0; i<=9; i++){ //validacion de que el orden no fue ingresado aun, sin llegar a guardar nada nuevo el vector
                    if(posicion == valid[i]){
                        p("Orden ya ingresado, reintentelo\n");
                        flag = 1;
                    }
                }
            }while (flag != 0);

            valid[vuelta]=posicion;
        }while(posicion > 10);// loop por si se ingresa mal la posicion

        p("Ingrese el numero ganador:\n");
        sc("%d", &x[posicion-1]);   //ingreso y guardado en la posicion adecuada
        vuelta++;

    }while(vuelta < 10);

    return x; //devuelve el Vector entero, noo hacen falta corchetes
}