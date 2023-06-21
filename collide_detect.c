/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** collisions file
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "include/my.h"
#include "include/set_wind_struct.h"
#include "include/sprite_struct.h"

int vect_in_rect(sfVector2f vect, sfFloatRect rect)
{
    if (vect.x > rect.left && vect.x < (rect.left + rect.width) &&
vect.y > rect.top && vect.y < (rect.top + rect.height))
        return (1);
    return (0);
}

int tower_area(sfVector2f sqr, tower_t *tow)
{
    while (tow != NULL) {
        double dist = sqrt(pow((sqr.x - tow->pos.x), 2.00)
        + pow((sqr.y - tow->pos.y), 2.00));
        sfVector2f line = (sfVector2f){sqr.x - tow->pos.x, sqr.y - tow->pos.y};
        sfVector2f unit_vect = (sfVector2f) {line.x / dist, line.y / dist};
        if (tow->radius < dist) {
            unit_vect.x *= tow->radius;
            unit_vect.y *= tow->radius;
        } else
            return (1);
        sfVector2f point =
        (sfVector2f){tow->pos.x + unit_vect.x, tow->pos.y + unit_vect.y};
        sfFloatRect square = (sfFloatRect) {sqr.x - 10, sqr.y - 10, 20, 20};
        int inter = vect_in_rect(point, square);
        if (inter == 1)
            return (1);
        tow = tow->next;
    }
    return (0);
}

int collide_step_2(tower_t *check_tower, plane_t *check_plane)
{
    while (check_tower != NULL) {
        if (tower_area(check_plane->current, check_tower) == 1)
            return (1);
        check_tower = check_tower->next;
    }
    return (0);
}

void collide(plane_t **plane, tower_t **tower, set_wind_t *wind)
{
    plane_t *check_plane = *plane, *check_2plane = (*plane)->next;
    tower_t *check_tower = *tower;
    if ((*plane)->next == NULL)
        return;
    while (check_plane != NULL) {
        check_plane->not_safe = collide_step_2(check_tower, check_plane);
        check_plane = check_plane->next;
    }
    check_plane = *plane;
    while (check_plane->next != NULL) {
        while (check_2plane != NULL) {
            popping_plane(check_plane, check_2plane, wind);
            check_2plane = check_2plane->next;
        }
        check_plane = check_plane->next;
        check_2plane = check_plane->next;
    }
}
