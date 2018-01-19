/*
** EPITECH PROJECT, 2017
** Main
** File description:
** Main File
*/

#include "hunter.h"

void mh_game_loop(struct s_mh_obj *obj)
{
	while (sfRenderWindow_isOpen(obj->window)) {
		sfRenderWindow_clear(obj->window, sfBlue);
		sfRenderWindow_drawSprite(obj->window, obj->bg.sprite, NULL);
		mh_lives_draw(obj);
		mh_score_draw(obj);
		mh_boss_draw(obj);
		mh_target_clock(obj);
		mh_explosion_clock(obj);
		mh_event_reach_top(obj);
		mh_boss_bounce(obj);
		mh_event_loop(obj);
		sfRenderWindow_drawSprite(obj->window,
					  obj->target.sprite, NULL);
		mh_gui_draw(obj);
		mh_cursor_draw(obj);
		sfRenderWindow_display(obj->window);
	}
}

int main()
{
	struct s_mh_obj obj;

	mh_init(&obj);
	mh_target_replace(&obj);
	mh_game_loop(&obj);
	sfRenderWindow_destroy(obj.window);
	return (0);
}
