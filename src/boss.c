/*
** EPITECH PROJECT, 2017
** Boss
** File description:
** Boss Manager
*/

#include "hunter.h"

void mh_boss_anime(struct s_mh_obj *obj)
{
	sfIntRect spritePos = sfSprite_getTextureRect(obj->boss.sprite);
	int pixHeight = spritePos.height * (obj->boss.config[0] - 1);
	int pixWidth = spritePos.width * (obj->boss.config[1] - 1);
	int pixLastWidth = spritePos.width * (obj->boss.config[2] - 1);

	if (spritePos.top >= pixHeight && spritePos.left >= pixLastWidth) {
		spritePos.top = 0;
		spritePos.left = 480;
	}
	else if (spritePos.left <= pixWidth)
		spritePos.left += spritePos.width;
	else {
		spritePos.left = 0;
		if (spritePos.top < pixHeight)
			spritePos.top += spritePos.height;
		else
			spritePos.top = 0;
	}
	sfSprite_setTextureRect(obj->boss.sprite, spritePos);
}

void mh_boss_draw(struct s_mh_obj *obj)
{
	if (obj->boss.active) {
		mh_boss_clock(obj);
		sfRenderWindow_drawSprite(obj->window, obj->boss.sprite, NULL);
		mh_boss_draw_health(obj);
	}
}

void mh_boss_active(struct s_mh_obj *obj)
{
	obj->boss.active = 1;
	mh_sprite_centrer(obj, obj->boss.sprite);
}

void mh_boss_clock(struct s_mh_obj *obj)
{
	sfTime times[2];

	times[0] = sfClock_getElapsedTime(obj->boss.clock);
	times[1] = sfClock_getElapsedTime(obj->boss.move.clock);
	if (sfTime_asMilliseconds(times[0]) > 90) {
		if (!obj->ui.paused && obj->boss.active)
			mh_boss_anime( obj);
		sfClock_restart(obj->boss.clock);
	}
	if (sfTime_asMilliseconds(times[1]) > 50) {
		if (!obj->ui.paused && obj->boss.active)
			sfSprite_move(obj->boss.sprite, obj->boss.move.vector);
		sfClock_restart(obj->boss.move.clock);
	}
}