#include <stdio.h>
#include <string.h>

int main(){
    char wrd[100];
    printf("Geben sie ein Wort ein:");
    
    if(scanf("%99s", wrd) != 1){
        printf("Fehlerhafte Eingabe");
        return 1;
    }
    printf("test");
}