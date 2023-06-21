/*
** EPITECH PROJECT, 2022
** My_hunter
** File description:
** set_wind_struct
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

#ifndef SET_WIND_STRUCT_H
    #define SET_WIND_STRUCT_H

        typedef struct drak_velocity{
            int x;
            int y;
        }drak_velocity_t;

        typedef struct set_wind{
            sfRenderWindow *window;
            sfVideoMode V_mode;
            sfEvent event;
            int show_box;
            int show_sprite;
            sfView *view;
            sfClock *clock;
            double frames;
            int done;
            int planen;
            sfFloatRect Jerry_Hitbox;
            sfVector2f Jerry_Coords;
            sfRectangleShape *plane_box;
            sfBool klik;
        }set_wind_t;

#endif /*SET_WIND_STRUCT_H*/
