/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** display, one by one, the characters of a string
*/
void my_putchar(char c);

int my_putstr(char const *str)
{
    int len;

    for (len = 0; (char)str[len] != (char)0 ; len ++) {
        my_putchar(str[len]);
    }
    return (0);
}
