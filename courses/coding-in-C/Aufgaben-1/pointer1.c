#include <stdio.h>

void main(){
    int myNumbers [5] = {10, 20, 30, 40, 50};
    int *ptr = &myNumbers [1];
    int *ptr2 = &myNumbers [4];
    printf("Adresse von Wert 1: %x\n", ptr); 
    printf("Adresse von Wert 4: %x\n", ptr2);
    printf("Differenz der Adressen: %x\n", ptr2 - ptr);
}