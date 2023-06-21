/*
** EPITECH PROJECT, 2022
** my_strlowcase
** File description:
** return every characteres of a string to lower case
*/
int my_strlen(char const *str);

char *my_strlowcase(char *str)
{
    int i;
    int len;

    len = my_strlen(str);
    for (i = 0; i <= len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
    }
    return (str);
}
