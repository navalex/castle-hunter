/*
** EPITECH PROJECT, 2017
** Events Boss
** File description:
** Boss Events
*/

#include <SFML/Window.h>
#include <SFML/Graphics/Rect.h>
#include "hunter.h"

void mh_event_boss_click(struct s_mh_obj *obj)
{
	sfVector2i mousePos = sfMouse_getPositionRenderWindow(obj->window);
	sfFloatRect boxPos = sfSprite_getGlobalBounds(obj->boss.sprite);

	if (!obj->ui.paused && obj->boss.active) {
		if (sfFloatRect_contains(&boxPos,
					 (float) mousePos.x,
					 (float) mousePos.y)) {
			mh_boss_hit(obj);
		}
		else
			mh_lives_down(obj, 10);
	}
}

void mh_boss_bounce(struct s_mh_obj *obj)
{
	sfVector2u win_size = sfRenderWindow_getSize(obj->window);
	sfFloatRect rect = sfSprite_getGlobalBounds(obj->boss.sprite);

	if (rect.top <= 0)
		obj->boss.move.vector.y = mh_rand(10, 20);
	else if (rect.top + rect.height >= win_size.y)
		obj->boss.move.vector.y = mh_rand(-20, -10);
	if (rect.left <= 0)
		obj->boss.move.vector.x = mh_rand(10, 20);
	else if (rect.left + rect.width >= win_size.x)
		obj->boss.move.vector.x = mh_rand(-20, -10);
}
