/*
** EPITECH PROJECT, 2017
** Init GUI
** File description:
** Graphical User Interface initialization
*/

#include "hunter.h"

struct s_mh_health mh_init_health()
{
	struct s_mh_health health;

	health.wrapper = mh_init_sprite(SPRITE_HEALTHBAR);
	health.bar = mh_init_sprite(SPRITE_HEALTHINNER);
	health.bg = mh_init_sprite(SPRITE_HEALTBG);
	mh_sprite_positionner(health.bg, 40, 20);
	mh_sprite_positionner(health.bar, 40, 20);
	mh_sprite_positionner(health.wrapper, 10, 0);
	return (health);
}

sfText *mh_init_gui_text(char *str, int unsigned size)
{
	sfText *text;
	sfFont *font;

	font = sfFont_createFromFile("font/Double_Bubble_shadow.otf");
	text = sfText_create();
	sfText_setString(text, str);
	sfText_setFont(text, font);
	sfText_setCharacterSize(text, size);
}

sfText *mh_init_gui_score(struct s_mh_obj *obj)
{
	sfText *text = mh_init_gui_text("0", 30);
	sfVector2f position = {sfRenderWindow_getSize(obj->window).x - 190, 5};

	sfText_setPosition(text, position);
	return (text);
}

void mh_init_gui_btn(struct s_mh_ui *ui)
{
	ui->btns = malloc(sizeof(struct s_mh_ui_btn) * GUI_BTN_NB);

	ui->btns[0] = mh_gui_btn_create("Restart", 2);
	ui->btns[1] = mh_gui_btn_create("Exit", 1);
}

struct s_mh_ui mh_init_gui(struct s_mh_obj *obj)
{
	struct s_mh_ui ui;
	sfVector2u windowsSize = sfRenderWindow_getSize(obj->window);

	ui.left = mh_init_sprite(SPRITE_UI_LEFT);
	ui.wrapper = mh_init_sprite(SPRITE_UI_PAUSEWRAPPER);
	ui.title = mh_init_gui_text("", 70);
	ui.paused = 0;
	ui.ended = 0;
	mh_sprite_set_rect(ui.wrapper, 800, 935, 550, 745);
	mh_sprite_positionner(ui.left, windowsSize.x - 250, 0);
	mh_sprite_positionner(ui.wrapper, windowsSize.x / 2 - (550 / 2),
			      windowsSize.y / 2 - (745 / 2));
	mh_init_gui_btn(&ui);
	return (ui);
}
