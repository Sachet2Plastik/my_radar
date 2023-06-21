/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** error handeling file
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "include/my.h"

int print_err(void)
{
    write(2, "Failed to open the script file\n", 31);
    return (84);
}

int usage(void)
{
    mini_printf("Air traffic simulation pannel\n\n");
    mini_printf("USAGE\n  ./my_radar [OPTION] path_to_script\n");
    mini_printf("   path_to_script     The path to the script file.\n\n");
    mini_printf("OPTIONS\n  -h            print the usage and quit.\n\n");
    mini_printf("USER INTERACTIONS\n");
    mini_printf("  'L' key       enable/disable hitboxes and areas.\n");
    mini_printf("  'S' key       enable/disable sprites.\n");
    return (0);
}

int open_verif(char *av)
{
    FILE *fd;
    fd = fopen(av, "r");
    if (fd == NULL)
        return (print_err());
    return (0);
}

int verif_file(char *buff)
{
    int i, arg = 0, arg_lim = 0;
    if (buff[0] == 'A')
        arg_lim = 6;
    else if (buff[0] == 'T')
        arg_lim = 3;
    else
        return (1);
    for (i = 1; buff[i] != '\0'; i++) {
        if (buff[i] != '\n' && buff[i] != 9 & buff[i] != ' ' &&
        (buff[i] < '0' || buff[i] > '9'))
            return (1);
        if (buff[i] == ' ' || buff[i] == '\t')
            arg += 1;
    }
    if (arg != arg_lim)
        return (1);
    return (0);
}

int verif(char *path)
{
    int err = 0, empty = 0;
    FILE *fd;
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    fd = fopen(path, "r");
    while ((nread = getline(&line, &len, fd)) != -1) {
        err += verif_file(line);
        empty = 1;
    }
    if (empty == 0)
        return (1);
    free(line);
    fclose(fd);
    return (err);
}
