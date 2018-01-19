/*
** EPITECH PROJECT, 2017
** Include Events
** File description:
** Events Prototypes
*/

#ifndef MY_HUNTER_INCLUDE_EVENTS_H
#define MY_HUNTER_INCLUDE_EVENTS_H

void mh_event_reach_top(struct s_mh_obj *obj);
void mh_event_target_click(struct s_mh_obj *obj);
void mh_event_loop(struct s_mh_obj *obj);
void mh_event_boss_click(struct s_mh_obj *obj);
void mh_event_menu(struct s_mh_obj *obj);
void mh_cursor_draw(struct s_mh_obj *obj);
void mh_boss_bounce(struct s_mh_obj *obj);
void mh_event_menu_hover(struct s_mh_obj *obj);

#endif //MY_HUNTER_INCLUDE_EVENTS_H
