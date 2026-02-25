#include "C:\Users\yasin\Programmieren1\courses\coding-in-C\Aufgaben-1\string_utlis_project\include\string_utils.h"

#include <stdio.h>
#include <stdlib.h>

size_t custom_len(const char *str){
    size_t length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

