#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
    if(argc < 2){
        printf("Bitte 2 Argumente angeben.\n");
        return 1;
    }
    for(int i = 0; i < argc; i ++){
        printf("Index : %d\n", i);
        printf("Adresse : %p\n", argv[i]);
        printf("Inhalt : %s\n", argv[i]);
        printf("Laenge : %lu\n", strlen(argv[i]));
    }
    
}