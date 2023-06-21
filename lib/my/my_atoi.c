/*
** EPITECH PROJECT, 2022
** str to int
** File description:
** foncion atoi
*/

#include <stdio.h>

int my_atoi(char *str)
{
    int i = 0;
    int nb = 0;
    int tmp = 0;
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9')
            nb = nb * 10 + (str[i] - 48);
        i ++;
    }
    i = 0;
    while (str[i] != '\0') {
        if (str[i] == '-' && str[i + 1] >= '0' && str[i + 1] <= '9') {
            tmp = nb * 2;
            nb = nb - tmp;
        }
        i ++;
    }
    return (nb);
}
