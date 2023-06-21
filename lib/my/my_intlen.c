/*
** EPITECH PROJECT, 2022
** my_intlen
** File description:
** returns the len of an integer
*/

int my_intlen(int n)
{
    int len = 0;
    int i;
    int rest;

    for (i = 0; n != 0; i++) {
        rest = n % 10;
        n /= 10;
        len ++;
    }
    return (len);
}
