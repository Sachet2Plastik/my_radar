/*
** EPITECH PROJECT, 2022
** my_strupcase
** File description:
** puts every letter of a string in uppercase
*/
int my_strlen(char const *str);

char *my_strupcase(char *str)
{
    int i;
    int len;

    len = my_strlen(str);
    for (i = 0; i <= len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
    }
    return (str);
}
