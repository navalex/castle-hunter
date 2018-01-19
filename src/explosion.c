/*
** EPITECH PROJECT, 2017
** Explosion
** File description:
** Explosion Manager
*/

#include "hunter.h"

void mh_explosion_draw(struct s_mh_obj *obj)
{
	sfIntRect spritePos = sfSprite_getTextureRect(obj->explosion.sprite);
	int pixHeight = spritePos.height * (obj->explosion.config[0] - 1);
	int pixWidth = spritePos.width * (obj->explosion.config[1] - 1);
	int pixLastWidth = spritePos.width * (obj->explosion.config[2] - 1);

	if (spritePos.top >= pixHeight && spritePos.left >= pixLastWidth) {
		obj->explosion.active = 2;
	}
	else if (spritePos.left < pixWidth)
		spritePos.left += spritePos.width;
	else {
		spritePos.left = 0;
		if (spritePos.top < pixHeight)
			spritePos.top += spritePos.height;
	}
	sfSprite_setTextureRect(obj->explosion.sprite, spritePos);
}

void mh_explosion_fall(struct s_mh_obj *obj)
{
	sfVector2f spritePos = sfSprite_getPosition(obj->explosion.sprite);
	sfVector2f move = {0, 18};

	if (spritePos.y > 1080) {
		obj->explosion.active = 0;
		sfSprite_setTextureRect(obj->explosion.sprite,
					obj->explosion.rect);
	}
	else if (obj->ui.paused != 1) {
		sfSprite_move(obj->explosion.sprite, move);
	}
}

void mh_explosion_clock(struct s_mh_obj *obj)
{
	sfTime time = sfClock_getElapsedTime(obj->explosion.clock);

	if (obj->explosion.active > 0) {
		if (sfTime_asMilliseconds(time) > EXPL_CLOCKER &&
		    obj->explosion.active == 1 &&
		    !obj->ui.paused) {
			mh_explosion_draw(obj);
			sfClock_restart(obj->explosion.clock);
		}
		if (sfTime_asMilliseconds(time) > 50 &&
		    obj->explosion.active == 2 &&
		    !obj->ui.paused) {
			mh_explosion_fall(obj);
		}
		sfRenderWindow_drawSprite(obj->window,
					  obj->explosion.sprite, NULL);
	}
}
