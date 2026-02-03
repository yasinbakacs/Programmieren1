#include <stdio.h>

int main(){
    int Zeile[] = {1, 2, 3, 4, 5, 6, 7, 8};
    char Spalte[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    for(int i = 7; i >= 0; i--){
        for(int j = 0; j < 8; j++){
            printf("%c%d ", Spalte[j], Zeile[i]);
        }
        printf("\n");
    }
}