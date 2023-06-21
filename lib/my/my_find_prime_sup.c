/*
** EPITECH PROJECT, 2022
** my_find_prime_sup
** File description:
** return the smallest prime number that is greater than,
** or equal to, the number given as parameter
*/

int my_is_prime(int nb)
{
    int i;
    int div;

    div = nb / 2;
    if (nb == 0 || nb == 1)
        return (0);
    if (nb == 2147483647)
        return (1);
    if (nb > 2147483647 || nb < 0)
        return (0);
    for (i = 2; i <= div; i ++) {
        if (nb % i == 0) {
            return (0);
            }
    }
    return (1);
}

int my_find_prime_sup(int nb)
{
    int n;

    n = my_is_prime(nb);
    if (n == 1)
        return (nb);
    if (n == 0)
        return (my_find_prime_sup(nb + 1));
    return (0);
}
