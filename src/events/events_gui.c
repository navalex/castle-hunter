/*
** EPITECH PROJECT, 2017
** Events Gui
** File description:
** Gui Events
*/

#include <SFML/Graphics/Rect.h>
#include "hunter.h"

void mh_gui_menu_action(struct s_mh_obj *obj, int code)
{
	switch (code) {
	case 2:
		mh_restart(obj);
		break;
	case 1:
		sfRenderWindow_close(obj->window);
		break;
	default:
		break;
	}
}

void mh_event_menu(struct s_mh_obj *obj)
{
	sfVector2i mousePos = sfMouse_getPositionRenderWindow(obj->window);
	sfFloatRect btnRect;
	sfSprite *btn_sprite = NULL;
	int i = 0;

	if (obj->ui.paused || obj->ui.ended) {
		while (i < GUI_BTN_NB) {
			btn_sprite = obj->ui.btns[i].sprite;
			btnRect = sfSprite_getGlobalBounds(btn_sprite);
			if (sfFloatRect_contains(&btnRect,
						 (float)mousePos.x,
						 (float)mousePos.y)) {
				mh_gui_btn_rect(obj->ui.btns[i].sprite, 2);
				mh_gui_menu_action(obj, obj->ui.btns[i].code);
				mh_gui_btn_rect(obj->ui.btns[i].sprite, 0);
			}
			i++;
		}
	}
}

void mh_event_menu_hover(struct s_mh_obj *obj)
{
	sfVector2i mousePos = sfMouse_getPositionRenderWindow(obj->window);
	sfFloatRect btnRect;
	sfSprite *btn_sprite = NULL;
	int i = 0;

	if (obj->ui.paused || obj->ui.ended) {
		while (i < GUI_BTN_NB) {
			btn_sprite = obj->ui.btns[i].sprite;
			btnRect = sfSprite_getGlobalBounds(btn_sprite);
			if (sfFloatRect_contains(&btnRect,
						 (float)mousePos.x,
						 (float)mousePos.y)) {
				mh_gui_btn_rect(obj->ui.btns[i].sprite, 1);
			}
			else {
				mh_gui_btn_rect(obj->ui.btns[i].sprite, 0);
			}
			i++;
		}
	}
}
