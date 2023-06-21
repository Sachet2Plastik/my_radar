/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** main file
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include "include/my.h"
#include "include/sprite_struct.h"

int init_window(tower_t **tower, plane_t **plane, int planen)
{
    set_wind_t wind;

    setwind(&wind);
    wind.planen = planen;
    return (game_loop(tower, plane, &wind));
}

int tower_plane(char *av)
{
    int err = 0, planen = 0;
    FILE *fd;
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    tower_t *tower = NULL;
    plane_t *plane = NULL;

    fd = fopen(av, "r");
    while ((nread = getline(&line, &len, fd)) != -1) {
        if (line[0] == 'A') {
            create_linkplane(&plane, line);
            planen += 1;
        } if (line[0] == 'T')
            create_linktower(&tower, line);
    }
    free(line);
    fclose(fd);
    return (init_window(&tower, &plane, planen));
}

int main(int ac, char** av)
{
    int test = 0;
    if (ac != 2)
        return (84);
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h')
        return (usage());
    if (test = open_verif(av[1]) == 84)
        return (84);
    test = verif(av[1]);
    if (test != 0) {
        write(2, "script file contains illegal charactere: ", 42);
        write(2, "it can only take integers, 'A' \
for plane and 'T' for towers\n", 60);
        return (84);
    }
    return (tower_plane(av[1]));
}
