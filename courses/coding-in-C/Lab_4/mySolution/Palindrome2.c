#include <stdio.h>

void changeString(char *a);

void main(){
    char str[] = "AAtions speak louder than words";
    char *ptr = str;
    printf("%s\n", str);
    changeString(ptr);
    printf("%s\n", ptr);
}

void changeString(char *a){
    a[1] = 'c';

}