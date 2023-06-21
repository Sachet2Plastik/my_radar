/*
** EPITECH PROJECT, 2022
** my_strncpy
** File description:
** copies 'n' characters from a string to another
*/
int my_strlen(char const *str);

char *my_strncpy(char *dest, char const *src, int n)
{
    int lensrc;
    int lendest;
    int i;

    i = 0;
    lendest = my_strlen(dest);
    lensrc = my_strlen(src);

    while (i < n && src[i] != '\0') {
        dest[i] = src[i];
        i += 1;
    }
    if (lendest > lensrc) {
        while (i < n) {
            dest[i] = '\0';
            i += 1;
        }
    }
    return (dest);
}
