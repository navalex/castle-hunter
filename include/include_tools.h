/*
** EPITECH PROJECT, 2017
** Include Tools
** File description:
** Tools Prototypes
*/

#include "libs.h"

#ifndef MY_HUNTER_INCLUDE_TOOLS_H
#define MY_HUNTER_INCLUDE_TOOLS_H

/* Sprites Tools */
sfSprite *mh_init_sprite(char *img);
void mh_sprite_scaler(sfSprite *sprite, float x, float y);
void mh_sprite_positionner(sfSprite *sprite, float x, float y);
void mh_sprite_centrer(struct s_mh_obj *obj, sfSprite *sprite);
void mh_sprite_set_rect(sfSprite *sprite, int left, int top, int width,
			int height);
/* GUI Tools */
void mh_gui_set_title(struct s_mh_obj *obj, char *str);
void mh_gui_btn_place(struct s_mh_obj *obj);
struct s_mh_ui_btn mh_gui_btn_create(char *name, int code);
void mh_gui_btn_rect(sfSprite *btn, int state);

/* Global Tools */
char *mh_itoa(int nb, char *res);
void mh_putstr(char *str);
int mh_rand(int a, int b);

#endif