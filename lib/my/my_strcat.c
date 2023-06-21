/*
** EPITECH PROJECT, 2022
** my_strcat
** File description:
** concatenates two strings
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int i, len, len2, indice;
    char *result;
    len = my_strlen(dest);
    len2 = my_strlen(src);
    result = malloc(sizeof(char)*(len + len2));
    for (i = 0; dest[i] != '\0'; i++) {
        result[i] = dest[i];
        indice ++;
    }
    for (i = 0; src[i] != '\0'; i ++) {
        result[indice + i] = src[i];
    }
    return (result);
}
