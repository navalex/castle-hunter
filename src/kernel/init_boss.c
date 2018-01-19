/*
** EPITECH PROJECT, 2017
** Init Boss
** File description:
** Boss Object initialization
*/

#include "hunter.h"

static struct s_mh_health mh_init_boss_health(struct s_mh_obj *obj)
{
	struct s_mh_health health;
	sfFloatRect rect;

	health.value 	= 100;
	health.wrapper 	= mh_init_sprite(SPRITE_BOSS_HEALTHBAR);
	health.bar	= mh_init_sprite(SPRITE_HEALTBG);
	mh_sprite_centrer(obj, health.wrapper);
	rect = sfSprite_getGlobalBounds(health.wrapper);
	rect.left += 30;
	rect.top = 30;
	rect.width -= 30;
	mh_sprite_positionner(health.wrapper, rect.left - 30, rect.top - 15);
	mh_sprite_positionner(health.bar, rect.left, rect.top);
	mh_sprite_set_rect(health.bar, 0, 0, BOSS_HEALTH_PX, 17);
	return (health);
}

struct s_mh_boss mh_init_boss(struct s_mh_obj *obj)
{
	struct s_mh_boss	boss;
	sfIntRect rect = {0, 0, BOSS_SPRITE_WIDTH, BOSS_SPRITE_HEIGHT};

	boss.sprite		= mh_init_sprite(SPRITE_BOSS);
	boss.clock		= sfClock_create();
	boss.move.clock		= sfClock_create();
	boss.active		= 0;
	boss.config[0]		= BOSS_SPRITE_ROWS;
	boss.config[1]		= BOSS_SPRITE_COLS;
	boss.config[2]		= BOSS_SPRITE_LCOLS;
	boss.health		= mh_init_boss_health(obj);
	sfSprite_setTextureRect(boss.sprite, rect);
	mh_sprite_scaler(boss.sprite, 4, 4);
	return (boss);
}
