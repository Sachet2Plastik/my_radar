/*
** EPITECH PROJECT, 2022
** my_swap
** File description:
** swap the content of two integers
*/

void my_swap(int *a, int *b)
{
    int x;

    x = *a;
    *a = *b;
    *b = x;
}
