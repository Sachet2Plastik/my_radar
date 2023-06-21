/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** create_linked_list
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "include/my.h"
#include "include/sprite_struct.h"

void create_linktower(tower_t **circle, char* line)
{
    tower_t *new_pos;
    tower_t *last = *circle;
    int pos = 2, x = take_args(line, &pos), y = take_args(line, &pos), rad;

    new_pos = malloc(sizeof(tower_t));
    rad = take_args(line, &pos) * 1920 / 100;
    new_pos->pos.x = x;
    new_pos->pos.y = y;
    new_pos->radius = rad;
    new_pos->next = NULL;
    new_pos->prev = NULL;
    if (*circle == NULL) {
        *circle = new_pos;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_pos;
    new_pos->prev = last;
}

void spam_args(plane_t **new_pos, char *line, int *pos)
{
    (*new_pos)->end.x = take_args(line, pos);
    (*new_pos)->end.y = take_args(line, pos);
    (*new_pos)->speed = take_args(line, pos);
    (*new_pos)->timer = take_args(line, pos);
}

void create_linkplane(plane_t **plane, char* line)
{
    plane_t *new_pos;
    plane_t *last = *plane;
    int pos = 2, sx = take_args(line, &pos), sy = take_args(line, &pos);
    new_pos = malloc(sizeof(plane_t));
    new_pos->done = new_pos->end_detect = new_pos->not_safe = 0;
    new_pos->start.x = new_pos->current.x = sx;
    new_pos->start.y = new_pos->current.y = sy;
    spam_args(&new_pos, line, &pos);
    new_pos->next = new_pos->prev = NULL;
    if (*plane == NULL) {
        *plane = new_pos;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_pos;
    new_pos->prev = last;
}
