#include <stdio.h>

void main(){
    char wrd[100];
    printf("Geben sie ein Wort ein:");
    scanf("%s", wrd);
    char *ptr = wrd;
    char *endPtr = ptr;
    while (*endPtr != '\0'){
        endPtr++;
    }
    endPtr--;
    printf("Ende des Wortes: %c\n", *endPtr);
    printf("Anfang des Wortes: %c\n", *ptr);
    while(*ptr != '\0'){
        if(*ptr != *endPtr){
            printf("Das Wort %s ist kein Palindrom.\n", wrd);
            break;
        }
        endPtr--;
        ptr++;
    }
    if(*ptr == '\0'){
    printf("Das Wort %s ist ein Palindrom.\n", wrd);
    }
}