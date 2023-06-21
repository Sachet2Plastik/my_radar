/*
** EPITECH PROJECT, 2022
** my_strncat
** File description:
** concatenates n characters of the src string to the end of the dest string
*/
int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int nb)
{
    int i;
    int len;

    len = my_strlen(dest);
    while (i < nb && src[i] != '\0') {
        dest[len + i] = src[i];
        i += 1;
    }
    dest[len + i] = '\0';
    return (dest);
}
