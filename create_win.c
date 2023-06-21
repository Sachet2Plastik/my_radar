/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** create window
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include "include/set_wind_struct.h"

void setwind(set_wind_t *wind)
{
    wind->V_mode.width = 1920;
    wind->V_mode.height = 1080;
    wind->V_mode.bitsPerPixel = 32;
    wind->view = sfView_create();
    wind->show_box = wind->show_sprite = 1;
    wind->frames = wind->done = wind->planen = 0;
    wind->plane_box = sfRectangleShape_create();
    wind->window = sfRenderWindow_create(wind->V_mode, "my_radar",\
    sfDefaultStyle, NULL);
}
