/*
** EPITECH PROJECT, 2017
** Include Kernel
** File description:
** Kernel Prototypes
*/

#include "libs.h"

#ifndef MY_HUNTER_INCLUDE_KERNEL_H
#define MY_HUNTER_INCLUDE_KERNEL_H

/* Global Initialisations */
void mh_init(struct s_mh_obj *obj);
void mh_restart(struct s_mh_obj *obj);
/* Window and Background */
sfRenderWindow *mh_init_window();
sfSprite *mh_init_cursor(struct s_mh_obj *obj);
struct s_mh_bg mh_init_bg(struct s_mh_obj *obj);
/* Target and explosion */
struct s_mh_target mh_init_target();
struct s_mh_explosion mh_init_explosion();
/* Player and stats */
struct s_mh_player mh_init_player();
struct s_mh_health mh_init_health();
/* GUI */
struct s_mh_ui mh_init_gui(struct s_mh_obj *obj);
sfText *mh_init_gui_text(char *str, int unsigned size);
sfText *mh_init_gui_score(struct s_mh_obj *obj);
/* Boss */
struct s_mh_boss mh_init_boss(struct s_mh_obj *obj);

#endif //MY_HUNTER_INCLUDE_KERNEL_H
