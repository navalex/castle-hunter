/*
** EPITECH PROJECT, 2017
** Score
** File description:
** Score Manager
*/

#include "hunter.h"

void mh_score_reset(struct s_mh_obj *obj)
{
	sfText_setString(obj->score, "0");
}

void mh_score_up(struct s_mh_obj *obj)
{
	char scoreText[4];

	obj->player.score += 1;
	mh_itoa(obj->player.score, scoreText);
	sfText_setString(obj->score, scoreText);
	obj->target.move.vector.y -= 2;
	if (obj->player.score % 15 == 0)
		mh_boss_active(obj);
}

void mh_score_draw(struct s_mh_obj *obj)
{
	sfRenderWindow_drawSprite(obj->window, obj->ui.left, NULL);
	sfRenderWindow_drawText(obj->window, obj->score, NULL);
}
