/*
** EPITECH PROJECT, 2022
** my_strncmp.c
** File description:
** task07
*/

static int str_len(char const *str, int nb)
{
    int len = 0;
    for (int i = 0; i < nb - 1; i++){
        if (str[i] == '\0')
            return (len);
        len++;
    }
    return (len);
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int len_s1 = str_len(s1, n);
    int len_s2 = str_len(s2, n);
    if (len_s1 > len_s2)
        return (1);
    if (len_s1 < len_s2)
        return (-1);
    for (int i = 0; i <= n; i++){
        if (s1[i] > s2[i])
            return (1);
        if (s1[i] < s2[i])
            return (-1);
    }
    return (0);
}
