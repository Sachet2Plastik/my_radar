/*
** EPITECH PROJECT, 2022
** my_strncmp
** File description:
** reproduce the behavior of the strncmp function
*/
int my_strlen(char const *str);

int my_strcmp(char const *s1, char const *s2, int n)
{
    int somme1 = 0;
    int somme2 = 0;
    int len1;
    int len2;
    int i;
    int j;

    len1 = my_strlen(s1) - 1;
    len2 = my_strlen(s2) - 1;
    for (i = 0; i <= len1 || i <= n; i++) {
        somme1 += (int) s1[i];
    }
        for (j = 0; j <= len2 || j <= n; j++) {
        somme2 += (int) s2[j];
    }
    return (somme1 - somme2);
}
