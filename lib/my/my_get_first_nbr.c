/*
** EPITECH PROJECT, 2022
** my_getnbr.c
** File description:
** task05
*/
#include <stdio.h>

static int my_len(char const *str)
{
    int len = 0;
    int i = 0;
    while (str[i] != '\0'){
        len++;
        i++;
    }
    return (len);
}

static int isneg(char const *str, int neg, int i)
{
    if (str[i - 1] == '-'){
        neg = -1;
        return (neg);
    }
    return (neg);
}

static int overflow(char const *str, int nb, int i, int *bool)
{
    int over;
    over = nb * 10 + (str[i] - 48);
    if (over < 0){
        *bool = 1;
        nb = 0;
        return (nb);
    } else {
        nb = nb * 10 + (str[i] - 48);
        return (nb);
    }
}

int my_get_first_nbr(char const *str)
{
    int len = my_len(str);
    int nb = 0;
    int neg = 1;
    int stopf = 0;
    int stopw = 0;
    for (int i = 0; stopf != 1 && i < len; i++){
        if ((str[i] > 'a' && str[i] < 'z') && (str[i] != '-' && str[i] != '+'))
            return (0);
        while ((str[i] >= '0' && str[i] <= '9') && stopw == 0){
            neg = isneg(str, neg, i);
            nb = overflow(str, nb, i, &stopw);
            i++;
            stopf = 1;
        }
    }
    if (nb == 0){
        return (0);
    }
    return (nb * neg);
}
