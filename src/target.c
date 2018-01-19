/*
** EPITECH PROJECT, 2017
** Target
** File description:
** Target Manager
*/

#include "hunter.h"

void mh_target_move(struct s_mh_obj *obj)
{
	if (obj->explosion.active == 0)
		sfSprite_move(obj->target.sprite,
			      obj->target.move.vector);
}

void mh_target_anime(struct s_mh_obj *obj)
{
	sfIntRect spritePos = sfSprite_getTextureRect(obj->target.sprite);
	int pixHeight = spritePos.height * (obj->target.config[0] - 1);
	int pixWidth = spritePos.width * (obj->target.config[1] - 1);
	int pixLastWidth = spritePos.width * (obj->target.config[2] - 1);

	if (spritePos.top >= pixHeight && spritePos.left >= pixLastWidth) {
		spritePos.top = 0;
		spritePos.left = 0;
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
	sfSprite_setTextureRect(obj->target.sprite, spritePos);
}

void mh_target_replace(struct s_mh_obj *obj)
{
	sfVector2u windowsSize = sfRenderWindow_getSize(obj->window);
	float randX = mh_rand(0, windowsSize.x - obj->target.rect.width);
	sfVector2f targetPos = {randX, windowsSize.y};

	sfSprite_setPosition(obj->target.sprite, targetPos);
}

void mh_target_clock(struct s_mh_obj *obj)
{
	sfTime times[2];

	times[0] = sfClock_getElapsedTime(obj->target.clock);
	times[1] = sfClock_getElapsedTime(obj->target.move.clock);
	if (sfTime_asMilliseconds(times[0]) > TARGET_CLOCKER) {
		if (!obj->ui.paused && !obj->boss.active)
			mh_target_anime(obj);
		sfClock_restart(obj->target.clock);
	}
	if (sfTime_asMilliseconds(times[1]) > TARGET_MOVE_CLOCKER) {
		if (!obj->ui.paused && !obj->boss.active)
			mh_target_move(obj);
		sfClock_restart(obj->target.move.clock);
	}
}
