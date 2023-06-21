/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** main_loop
*/

int take_args(char* data,int* pos)
{
    int dim = 0;
    for (*pos; data[*pos] != ' ' && data[*pos] != '\0' && data[*pos] != '\n'
    && data[*pos] != '\t'; *pos += 1) {
        dim *= 10;
        dim += (data[*pos] - 48);
    }
    *pos += 1;
    return (dim);
}
