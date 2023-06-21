/*
** EPITECH PROJECT, 2022
** My_hunter
** File description:
** sprite creation
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

#ifndef SPRITE_STRUCT_H
    #define SPRITE_STRUCT_H

    typedef struct setsprite{
        sfTexture *text;
        sfSprite *sprite;
    }setsprite_t;

    typedef struct tower{
        sfVector2f pos;
        float radius;
        int zone;
        struct tower *next;
        struct tower *prev;
    }tower_t;

    typedef struct plane {
        sfVector2f start;
        sfVector2f end;
        sfVector2f current;
        int not_safe;
        int speed;
        int timer;
        int zone;
        int end_detect;
        int done;
        struct plane *next;
        struct plane *prev;
    }plane_t;

#endif /*SPRITE_STRUCT_H*/
