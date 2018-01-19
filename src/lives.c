/*
** EPITECH PROJECT, 2017
** Lives
** File description:
** Lives Manager
*/

#include "hunter.h"

void mh_lives_down(struct s_mh_obj *obj, int down)
{
	sfIntRect rect = sfSprite_getTextureRect(obj->health.bar);

	obj->player.lives = obj->player.lives - down;
	if (obj->player.lives <= 0) {
		mh_gui_menu_end(obj);
	}

	rect.width -= (175 * down) / 100;
	sfSprite_setTextureRect(obj->health.bar, rect);
	obj->target.move.vector.y -= 2;
}

void mh_lives_draw(struct s_mh_obj *obj)
{
	sfRenderWindow_drawSprite(obj->window, obj->health.bg, NULL);
	sfRenderWindow_drawSprite(obj->window, obj->health.bar, NULL);
	sfRenderWindow_drawSprite(obj->window, obj->health.wrapper, NULL);
}
