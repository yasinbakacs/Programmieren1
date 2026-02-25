#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <stddef.h>


/*
 * @brief Calculates the length of a string.
 *
 * @param [in] const char *str: The input string.
 * @return Returns the length of the string (number of characters before the null terminator).
 */
size_t custom_len(const char *str);


/*
 * @brief Liest string von der Standardeingabe ein und gibt einen Zeiger auf den dynamisch allozierten String zurück. Der Speicher für den String wird innerhalb der Funktion allokiert und muss vom Aufrufer freigegeben werden.
 *
 * @param [in] char *str: The input string to be reversed. The string is modified in place.
 * @return Returns a pointer to the reversed string (same as the input pointer).
 */
char *read_line_dynamic(void);

#endif /* STRING_UTILS_H */