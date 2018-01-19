/*
** EPITECH PROJECT, 2017
** Init Target
** File description:
** Target Object initialization
*/

#include "hunter.h"

struct s_mh_target mh_init_target()
{
	struct s_mh_target	target;
	sfVector2f vector = {0, TARGET_MOVESPEED};
	sfIntRect rect = {0, 0, TARGET_SPRITE_WIDTH, TARGET_SPRITE_HEIGHT};

	target.sprite		= mh_init_sprite(SPRITE_TARGET);
	target.clock		= sfClock_create();
	target.move.clock	= sfClock_create();
	target.config[0]	= TARGET_SPRITE_ROWS;
	target.config[1]	= TARGET_SPRITE_COLS;
	target.config[2]	= TARGET_SPRITE_LCOLS;
	target.move.vector	= vector;
	target.rect		= rect;
	sfSprite_setTextureRect(target.sprite, target.rect);
	mh_sprite_scaler(target.sprite, TARGET_SCALEX, TARGET_SCALEY);
	return (target);
}

struct s_mh_explosion mh_init_explosion()
{
	struct s_mh_explosion explosion;
	sfIntRect rect = {0, 0, EXPL_SPRITE_WIDTH, EXPL_SPRITE_HEIGHT};

	explosion.sprite = mh_init_sprite(SPRITE_EXPLOSION);
	explosion.clock = sfClock_create();
	explosion.config[0] = EXPL_SPRITE_ROWS;
	explosion.config[1] = EXPL_SPRITE_COLS;
	explosion.config[2] = EXPL_SPRITE_LCOLS;
	explosion.active = 0;
	explosion.rect = rect;
	sfSprite_setTextureRect(explosion.sprite, explosion.rect);
	mh_sprite_scaler(explosion.sprite, EXPL_SCALEX, EXPL_SCALEY);
	return (explosion);
}

struct s_mh_player mh_init_player()
{
	struct s_mh_player player;

	player.lives = PLAYER_LIVES;
	player.score = PLAYER_SCORE;
	return (player);
}
