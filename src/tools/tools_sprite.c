/*
** EPITECH PROJECT, 2017
** Tools Sprite
** File description:
** Sprite tools
*/

#include <SFML/Window.h>
#include <SFML/Graphics/Rect.h>
#include "hunter.h"

void mh_sprite_scaler(sfSprite *sprite, float x, float y)
{
	sfVector2f scaler = {x, y};

	sfSprite_setScale(sprite, scaler);
}

void mh_sprite_positionner(sfSprite *sprite, float x, float y)
{
	sfVector2f position = {x, y};

	sfSprite_setPosition(sprite, position);
}

void mh_sprite_set_rect(sfSprite *sprite, int left, int top, int width,
			int height)
{
	sfIntRect rect = {left, top, width, height};

	sfSprite_setTextureRect(sprite, rect);
}

void mh_sprite_centrer(struct s_mh_obj *obj, sfSprite *sprite)
{
	sfVector2u window = sfRenderWindow_getSize(obj->window);
	sfFloatRect rect = sfSprite_getGlobalBounds(sprite);

	mh_sprite_positionner(sprite, window.x / 2 - rect.width / 2,
			      window.y / 2 - rect.height / 2);
}

sfSprite *mh_init_sprite(char *img)
{
	sfTexture *texture = sfTexture_createFromFile(img, NULL);
	sfSprite *sprite = sfSprite_create();

	sfSprite_setTexture(sprite, texture, sfTrue);
	return (sprite);
}
