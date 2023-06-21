/*
** EPITECH PROJECT, 2022
** my_compute_square_root
** File description:
** return the square root (if whole number)
** of the number given as argument
*/
int my_root_test(int search, int obj)
{
    int Dsearch;

    Dsearch = search * search;
    if (Dsearch == obj) {
        return (search);
    }
    if (Dsearch > obj) {
        return (0);
    }
    my_root_test(search + 1, obj);
}

int my_compute_square_root(int nb)
{
    int search = 1;

    return (my_root_test(search, nb));
}
