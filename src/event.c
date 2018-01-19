/*
** EPITECH PROJECT, 2017
** Event
** File description:
** Event Manager
*/

#include "hunter.h"

void mh_event_reach_top(struct s_mh_obj *obj)
{
	sfFloatRect targetPos = sfSprite_getGlobalBounds(obj->target.sprite);

	if (targetPos.top + targetPos.height < 0) {
		mh_lives_down(obj, 20);
		mh_target_replace(obj);
	}
}

void mh_handle_pause(struct s_mh_obj *obj, sfEvent event)
{
	if (event.type == sfEvtKeyPressed &&
	    sfKeyboard_isKeyPressed(sfKeyEscape)) {
		mh_gui_menu_pause(obj);
	}
}

void mh_event_target_click(struct s_mh_obj *obj)
{
	sfVector2i mousePos = sfMouse_getPositionRenderWindow(obj->window);
	sfFloatRect boxPos = sfSprite_getGlobalBounds(obj->target.sprite);

	if (!obj->ui.paused && !obj->boss.active) {
		if (sfFloatRect_contains(&boxPos,
					 (float) mousePos.x,
					 (float) mousePos.y)) {
			obj->explosion.active = 1;
			mh_sprite_positionner(obj->explosion.sprite,
					      boxPos.left, boxPos.top);
			sfClock_restart(obj->explosion.clock);
			mh_target_replace(obj);
			mh_score_up(obj);
		}
		else
			mh_lives_down(obj, 10);
	}
}

void mh_event_loop(struct s_mh_obj *obj)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(obj->window, &event)) {
		mh_handle_pause(obj, event);
		if (event.type == sfEvtClosed) {
			sfRenderWindow_close(obj->window);
		}
		if (event.type == sfEvtMouseButtonPressed &&
		    sfMouse_isButtonPressed(sfMouseLeft)) {
			mh_event_target_click(obj);
			mh_event_boss_click(obj);
			mh_event_menu(obj);
		}
		if (obj->ui.paused) {
			mh_event_menu_hover(obj);
		}
	}
}
