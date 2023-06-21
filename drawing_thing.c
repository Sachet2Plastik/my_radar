/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** draw file
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include "include/set_wind_struct.h"
#include "include/sprite_struct.h"

void draw_tower(set_wind_t *wind, tower_t **tower, sfVector2f position)
{
    tower_t *draw_tower = *tower;
    sfCircleShape *tower_box = sfCircleShape_create();
    sfCircleShape_setOutlineThickness(tower_box, 1);
    sfCircleShape_setFillColor(tower_box, sfTransparent);
    sfCircleShape_setOutlineColor(tower_box, sfYellow);
    while (draw_tower != NULL) {
        position.x = draw_tower->pos.x;
        position.y = draw_tower->pos.y;
        sfCircleShape_setRadius(tower_box, draw_tower->radius);
        sfCircleShape_setOrigin(tower_box,\
        (sfVector2f){draw_tower->radius,draw_tower->radius});
        sfCircleShape_setPosition(tower_box, position);
        sfRenderWindow_drawCircleShape(wind->window, tower_box, NULL);
        draw_tower = draw_tower->next;
    }
    sfCircleShape_destroy(tower_box);
}

void draw_plane(set_wind_t *wind, plane_t **plane, sfVector2f position)
{
    plane_t *draw_plane = *plane;
    sfRectangleShape_setSize(wind->plane_box, (sfVector2f) {20, 20});
    sfRectangleShape_setFillColor(wind->plane_box, sfTransparent);
    sfRectangleShape_setOutlineColor(wind->plane_box, sfYellow);
    sfRectangleShape_setOutlineThickness(wind->plane_box, 1);
    while (draw_plane != NULL) {
        if (draw_plane->done == 1) {
            draw_plane = draw_plane->next;
        } else {
        position.x = draw_plane->current.x;
        position.y = draw_plane->current.y;
        sfRectangleShape_setOrigin(wind->plane_box, (sfVector2f){10, 10});
        sfRectangleShape_setPosition(wind->plane_box, position);
        sfRenderWindow_drawRectangleShape(wind->window, wind->plane_box, NULL);
        draw_plane = draw_plane->next;
        }}
}

void display_tower(set_wind_t *wind, tower_t **tower, sfVector2f position)
{
    setsprite_t tower_sprite;
    tower_t *display_tour = *tower;
    tower_sprite.text = sfTexture_createFromFile("asset/tower.png", NULL);
    tower_sprite.sprite = sfSprite_create();
    sfSprite_setTexture(tower_sprite.sprite, tower_sprite.text, sfTrue);
    while (display_tour != NULL) {
        position.x = display_tour->pos.x - 10;
        position.y = display_tour->pos.y - 10;
        sfSprite_setPosition(tower_sprite.sprite, position);
        sfRenderWindow_drawSprite(wind->window, tower_sprite.sprite, NULL);
        display_tour = display_tour->next;
    }
    sfSprite_destroy(tower_sprite.sprite);
    sfTexture_destroy(tower_sprite.text);
}

void display_plane(set_wind_t *wind, plane_t **plane, sfVector2f position)
{
    setsprite_t plane_sprite;
    plane_t *display_avion = *plane;
    plane_sprite.text = sfTexture_createFromFile("asset/plane.png", NULL);
    plane_sprite.sprite = sfSprite_create();
    sfSprite_setTexture(plane_sprite.sprite, plane_sprite.text, sfTrue);
    while (display_avion != NULL) {
        if (display_avion->done == 1) {
            display_avion = display_avion->next;
        } else {
        position.x = display_avion->current.x - 10;
        position.y = display_avion->current.y - 10;
        sfSprite_setPosition(plane_sprite.sprite, position);
        sfRenderWindow_drawSprite(wind->window, plane_sprite.sprite, NULL);
        display_avion = display_avion->next;
        }}
    sfSprite_destroy(plane_sprite.sprite);
    sfTexture_destroy(plane_sprite.text);
}

void universal_draw(set_wind_t *wind, tower_t **tower, plane_t **plane)
{
    sfVector2f position;
    if (wind->show_box == 1) {
        draw_tower(wind, tower, position);
        draw_plane(wind, plane, position);
    }
    if (wind->show_sprite == 1) {
        display_tower(wind, tower, position);
        display_plane(wind, plane, position);
    }
}
