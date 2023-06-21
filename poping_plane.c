/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** poping_plane
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

void popping_plane(plane_t *ref, plane_t *checking, set_wind_t *wind)
{
    if (ref->done == 1 || checking->done == 1)
        return;
    if (ref->not_safe == 1 && checking->not_safe == 1)
        return;
    sfVector2f refTopLeft = {ref->current.x - 10, ref->current.y - 10};
    sfVector2f refBotRight = {ref->current.x + 10, ref->current.y + 10};
    sfVector2f checkTopLeft = {checking->current.x - 10, \
checking->current.y - 10};
    sfVector2f checkBotRight = {checking->current.x + 10, \
checking->current.y + 10};
    if ((refTopLeft.x < checkBotRight.x) && (refBotRight.x > checkTopLeft.x) &&
    (refTopLeft.y < checkBotRight.y) && (refBotRight.y > checkTopLeft.y)) {
        wind->done += 2;
        checking->done = 1;
        ref->done = 1;
    }
}
