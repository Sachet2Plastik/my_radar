/*
** EPITECH PROJECT, 2022
** my_sort_int_array
** File description:
** sort integer array in ascending order
*/

void move(int *array, int i, int j)
{
    int wait;

    if (array[i] > array[j]) {
        wait = array[i];
        array[i] = array[j];
        array[j] = wait;
    }
}

void my_sort_int_array(int *array, int size)
{
    int i;
    int j;

    for (i = 0; i < size; i ++) {
        for ( j = 1 ; j < size; j ++) {
            move(array, i, j);
        }
    }
}
