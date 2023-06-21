/*
** EPITECH PROJECT, 2022
** my_put_nbr.c
** File description:
** task07
*/

void my_putchar(char c);

static int isneg(int n)
{
    if (n < 0){
        return ('N');
    } else {
        return ('P');
    }
}

static int print_digits(int a)
{
    while (a > 0){
        int md = a % 10;
        my_putchar(48 + md);
        a = a / 10;
    }
}

static int reverse(int a)
{
    int nb = 0;
    while (a != 0){
        int mod = a % 10;
        nb = nb * 10 + mod;
        a = a / 10;
    }
    print_digits(nb);
}

int my_putnbr(int nb)
{
    if (isneg(nb) == 'N'){
        my_putchar(45);
        nb = nb * -1;
    }
    if (nb == 0){
        my_putchar(48);
    }
    reverse(nb);
}
