/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** move file
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

void check_end(float pos, plane_t *check, int s, set_wind_t *wind)
{
    if (s == 0) {
        if (check->end.x > check->start.x)
            check_x_positiv(check, wind);
        else
            check_x_negativ(check, wind);
    } else {
        if (check->end.y > check->start.y)
            check_y_positiv(check, wind);
        else
            check_y_negativ(check, wind);
    }
}

void check_x_y(plane_t **plane, set_wind_t *wind)
{
    plane_t *check = *plane;
    sfVector2f direction, unit_direction;
    int x_y = 0, len_vect = 0;

    while (check != NULL) {
        direction.x = check->end.x - check->start.x;
        direction.y = check->end.y - check->start.x;
        len_vect = sqrt(pow(direction.x, 2.00) + pow(direction.y, 2.00));
        unit_direction.x = (direction.x / len_vect) * check->speed;
        unit_direction.y = (direction.y / len_vect) * check->speed;
        if (unit_direction.x < unit_direction.y)
            x_y = 1;
        if (x_y == 0)
            check_end(unit_direction.x, check, x_y, wind);
        else
            check_end(unit_direction.y, check, x_y, wind);
        check = check->next;
    }
}

void change_current_pos(plane_t *plane_mv, set_wind_t *wind,\
sfVector2f unit_direction)
{
    plane_mv->current.x = plane_mv->start.x +
unit_direction.x * wind->frames;
    plane_mv->current.y = plane_mv->start.y +
unit_direction.y * wind->frames;
}

void move_plane(plane_t **plane, set_wind_t *wind)
{
    setsprite_t plane_sprite;
    plane_t *plane_mv = *plane;
    sfVector2f direction, unit_direction;
    int len_vect = 0;

    while (plane_mv != NULL) {
        if (plane_mv->done == 1) {
            plane_mv = plane_mv->next;
        } else {
            direction.x = plane_mv->end.x - plane_mv->start.x;
            direction.y = plane_mv->end.y - plane_mv->start.y;
            len_vect = sqrt(pow(direction.x, 2.00) + pow(direction.y, 2.00));
            unit_direction.x = (direction.x / len_vect) * plane_mv->speed;
            unit_direction.y = (direction.y / len_vect) * plane_mv->speed;
            sfRectangleShape_setPosition(wind->plane_box, unit_direction);
            change_current_pos(plane_mv, wind, unit_direction);
            check_x_y(&plane_mv, wind);
            plane_mv = plane_mv->next;
        }}
}
