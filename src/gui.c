/*
** EPITECH PROJECT, 2017
** Gui
** File description:
** Graphical User Interface Manager
*/

#include "hunter.h"

void mh_gui_toggle(struct s_mh_obj *obj, int state)
{
	switch (state) {
	case 0:
		obj->ui.paused = (obj->ui.paused) ? 0 : 1;
		break;
	case 1:
		obj->ui.ended = 1;
		obj->ui.paused = 1;
		break;
	case 2:
		obj->ui.ended = 0;
		obj->ui.paused = 0;
		break;
	default :
		break;
	}
}

void mh_gui_menu_pause(struct s_mh_obj *obj)
{
	if (!obj->ui.ended) {
		mh_gui_toggle(obj, 0);
		mh_gui_set_title(obj, "Pause");
	}
}

void mh_gui_menu_end(struct s_mh_obj *obj)
{
	mh_gui_toggle(obj, 1);
	mh_gui_set_title(obj, "Finish");
	mh_target_replace(obj);
}

void mh_gui_draw(struct s_mh_obj *obj)
{
	if (obj->ui.ended || obj->ui.paused) {
		sfRenderWindow_drawSprite(obj->window,
					  obj->ui.wrapper, NULL);
		sfRenderWindow_drawText(obj->window, obj->ui.title, NULL);
		mh_gui_btn_place(obj);
	}
}
