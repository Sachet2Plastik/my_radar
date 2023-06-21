/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** main_loop
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include "include/my.h"
#include "include/set_wind_struct.h"
#include "include/sprite_struct.h"

void show_hide_box(set_wind_t *wind)
{
    if (wind->show_box == 1) {
        wind->show_box = 0;
        return;
    }
    if (wind->show_box == 0) {
        wind->show_box = 1;
        return;
    }
}

void show_hide_entities(set_wind_t *wind)
{
    if (wind->show_sprite == 1) {
        wind->show_sprite = 0;
        return;
    }
    if (wind->show_sprite == 0) {
        wind->show_sprite = 1;
        return;
    }
}

void event_handeling(set_wind_t *wind)
{
    if (wind->event.type == sfEvtClosed)
        sfRenderWindow_close(wind->window);
    if (wind->event.type == sfEvtKeyPressed &&
    wind->event.key.code == sfKeyL)
        show_hide_box(wind);
    if (wind->event.type == sfEvtKeyPressed &&
    wind->event.key.code == sfKeyS)
        show_hide_entities(wind);
}

void end_loop_events(set_wind_t *wind)
{
    if (wind->event.type == sfEvtClosed)
        sfRenderWindow_close(wind->window);
    if (wind->event.type == sfEvtKeyPressed &&
    wind->event.key.code == sfKeyQ)
        sfRenderWindow_close(wind->window);
}
