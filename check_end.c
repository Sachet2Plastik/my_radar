/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** check end plane
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <math.h>
#include "include/my.h"
#include "include/set_wind_struct.h"
#include "include/sprite_struct.h"

void check_x_positiv(plane_t *check, set_wind_t *wind)
{
    if (check->current.x >= check->end.x) {
        check->done = 1;
        wind->done += 1;
    }
}

void check_x_negativ(plane_t *check, set_wind_t *wind)
{
    if (check->current.x <= check->end.x) {
        check->done = 1;
        wind->done += 1;
    }
}

void check_y_positiv(plane_t *check, set_wind_t *wind)
{
    if (check->current.y >= check->end.y) {
        check->done = 1;
        wind->done += 1;
    }
}

void check_y_negativ(plane_t *check, set_wind_t *wind)
{
    if (check->current.y <= check->end.y) {
        check->done = 1;
        wind->done += 1;
    }
}
