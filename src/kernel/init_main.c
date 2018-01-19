/*
** EPITECH PROJECT, 2017
** Main Init
** File description:
** Main Initialisation
*/

#include <SFML/Window.h>
#include "hunter.h"

static void mh_init_desc()
{
	mh_putstr("###################\n");
	mh_putstr("##               ##\n");
	mh_putstr("## Castle_Hunter ##\n");
	mh_putstr("##   By Navalex  ##\n");
	mh_putstr("##               ##\n");
	mh_putstr("###################\n");
}

void mh_init(struct s_mh_obj *obj)
{
	srand(time(NULL));
	obj->window	= mh_init_window();
	obj->bg		= mh_init_bg(obj);
	obj->target	= mh_init_target();
	obj->explosion	= mh_init_explosion();
	obj->player	= mh_init_player();
	obj->health	= mh_init_health();
	obj->score	= mh_init_gui_score(obj);
	obj->ui		= mh_init_gui(obj);
	obj->cursor	= mh_init_cursor(obj);
	obj->boss	= mh_init_boss(obj);
	mh_target_replace(obj);
	mh_init_desc();
}

void mh_restart(struct s_mh_obj *obj)
{
	obj->player = mh_init_player();
	obj->target.move.vector.y = TARGET_MOVESPEED;
	obj->health = mh_init_health();
	mh_score_reset(obj);
	mh_target_replace(obj);
	mh_gui_toggle(obj, 2);
}
