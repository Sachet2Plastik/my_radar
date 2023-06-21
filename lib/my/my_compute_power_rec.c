/*
** EPITECH PROJECT, 2022
** my_compute_power_rec
** File description:
** return the first argument raised to the power p
** (where p is the second argument) recursive function
*/

int my_compute_power_rec(int nb, int p)
{
    int result;

    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    result = 1;
    result = nb * my_compute_power_rec(nb, p - 1);
    if (result > 2147483647)
        return (0);
    return (result);
}
