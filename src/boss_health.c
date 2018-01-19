/*
** EPITECH PROJECT, 2017
** Boss Health
** File description:
** Boss health Manager
*/

#include "hunter.h"

void mh_boss_hit(struct s_mh_obj *obj)
{
	sfIntRect rect = sfSprite_getTextureRect(obj->boss.health.bar);

	obj->boss.health.value -= 5;
	rect.width -= (5 * BOSS_HEALTH_PX) / 100;

	if (obj->boss.health.value <= 0) {
		obj->boss.active = 0;
		obj->boss.health.value = 100;
		rect.width = BOSS_HEALTH_PX;
		mh_score_up(obj);
	}
	sfSprite_setTextureRect(obj->boss.health.bar, rect);
}

void mh_boss_draw_health(struct s_mh_obj *obj)
{
	sfRenderWindow_drawSprite(obj->window, obj->boss.health.bar, NULL);
	sfRenderWindow_drawSprite(obj->window, obj->boss.health.wrapper, NULL);
}