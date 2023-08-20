#include <stdio.h>

int main(){
    int n[10] = {2,4,6,9,15,64,22,69,87,10}, aux;

    for(int i = 0; i < 10; i++){

        for(int x = i+1; x <= 10; x++){

            if(n[x] < n[i]){
                aux = n[i];
                n[i] = n[x];
                n[x] = aux;
            }
        }
    }

    for (int z = 0; z < 10; z++){
        printf("\n%d)\t%d", z+1, n[z]);
    }
}