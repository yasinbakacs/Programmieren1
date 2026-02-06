#include <stdio.h>
void string(char)
void main(){
    char str[] = "Curly bird catches the worm";
    char *ptr = str;
    ptr [0] = 'E';
    ptr [1] = 'a';
    printf("string: %s\n", str);
    printf("pointer: %s\n", ptr);
}