/*
** EPITECH PROJECT, 2022
** my_isneg
** File description:
** afficher test nombre positif ou negatif
*/

void my_putchar(char c);

int my_isneg(int n)
{
    char result;

    result = 'X';
    if (n >= 0) {
        result = 'P';
        my_putchar(result);
    } else {
        result = 'N';
        my_putchar(result);
    }
    return (0);
}
