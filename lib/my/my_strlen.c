/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** count and return the len of a string
*/

int my_strlen(char const *str)
{
    int len;
    int lenMax;

    lenMax = 0;
    for (len = 0; (char)str[len] != (char)0 ; len ++) {
        lenMax += 1;
    }
    return (lenMax);
}
