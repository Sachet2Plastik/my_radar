/*
** EPITECH PROJECT, 2022
** my_revstr
** File description:
** reverses a string
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int debut = 0;
    int fin;
    char wait;

    fin = my_strlen(str) - 1;
    while (debut <= fin) {
            wait = str[debut];
            str[debut] = str[fin];
            str[fin] = wait;
            debut += 1;
            fin -= 1;
    }
    return (str);
}
