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
#include <stdlib.h>
#include "include/my.h"
#include "include/set_wind_struct.h"
#include "include/sprite_struct.h"

int end_loop(set_wind_t *wind)
{
    sfFont *font;
    font = sfFont_createFromFile("asset/font_asset/font.ttf");
    sfText *text;
    text = sfText_create();
    sfText_setFont(text, font);
    sfText_setString(text, "The Simulation has ended; press 'q' to quit.");
    sfText_setCharacterSize(text, 24);
    sfVector2f position;
    position.x = 700;
    position.y = 500;
    sfText_setPosition(text, position);
    while (sfRenderWindow_isOpen(wind->window)) {
        while (sfRenderWindow_pollEvent(wind->window, &wind->event))
            end_loop_events(wind);
        sfRenderWindow_clear(wind->window, sfBlack);
        sfRenderWindow_drawText(wind->window, text, NULL);
        sfRenderWindow_display(wind->window);
    }
    sfFont_destroy(font);
    sfText_destroy(text);
}

int game_loop(tower_t **tower, plane_t **plane, set_wind_t *wind)
{
    sfColor color = {150, 130, 210, 100};
    wind->clock = sfClock_create();
    while (sfRenderWindow_isOpen(wind->window)) {
        while (sfRenderWindow_pollEvent(wind->window, &wind->event))
            event_handeling(wind);
        if (sfClock_getElapsedTime(wind->clock).microseconds >= 40000) {
            move_plane(plane, wind);
            sfClock_restart(wind->clock);
            wind->frames += 0.24;
        }
        if (wind->done == wind->planen)
            end_loop(wind);
        collide(plane, tower, wind);
        sfRenderWindow_clear(wind->window, color);
        universal_draw(wind, tower, plane);
        sfRenderWindow_display(wind->window);
    }
    sfRenderWindow_destroy(wind->window);
}
