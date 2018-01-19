/*
** EPITECH PROJECT, 2017
** Include Structures
** File description:
** Structures of the game
*/

#include "libs.h"

struct s_mh_ui_btn
{
	sfSprite	*sprite;
	sfText		*text;
	int		code;
};

struct s_mh_ui
{
	sfSprite		*left;
	sfSprite		*wrapper;
	sfText			*title;
	unsigned int		paused;
	unsigned int		ended;
	struct s_mh_ui_btn	*btns;
};

struct s_mh_health
{
	sfSprite	*wrapper;
	sfSprite	*bar;
	sfSprite	*bg;
	int 		value;
};

struct s_mh_player
{
	int	lives;
	int	score;
};

struct s_mh_sprite_move
{
	sfClock		*clock;
	sfVector2f	vector;
};

struct s_mh_target
{
	sfSprite		*sprite;
	sfClock			*clock;
	int			config[3];
	struct s_mh_sprite_move	move;
	sfIntRect		rect;
};

struct s_mh_explosion
{
	sfSprite	*sprite;
	sfClock		*clock;
	int		config[3];
	sfIntRect	rect;
	int		active;
};

struct s_mh_bg
{
	sfSprite *sprite;
};

struct s_mh_boss
{
	sfSprite		*sprite;
	sfClock			*clock;
	int			config[3];
	struct s_mh_sprite_move	move;
	struct s_mh_health	health;
	int			active;
};

struct s_mh_obj
{
	sfRenderWindow		*window;
	sfText			*score;
	sfSprite		*cursor;
	struct s_mh_bg		bg;
	struct s_mh_target	target;
	struct s_mh_boss	boss;
	struct s_mh_explosion	explosion;
	struct s_mh_player	player;
	struct s_mh_health	health;
	struct s_mh_ui		ui;
};
