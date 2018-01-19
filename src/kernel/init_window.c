/*
** EPITECH PROJECT, 2017
** Init Window
** File description:
** Window Game initialization
*/

#include "hunter.h"

sfRenderWindow * mh_init_window()
{
	sfRenderWindow *window;
	sfVideoMode videoMode = sfVideoMode_getDesktopMode();

	window = sfRenderWindow_create(videoMode, WINDOW_TITLE,
				       sfDefaultStyle, NULL);
	sfRenderWindow_setFramerateLimit(window, 80);
	return (window);
}

struct s_mh_bg mh_init_bg(struct s_mh_obj *obj)
{
	struct s_mh_bg background;
	sfVector2u windowSize = sfRenderWindow_getSize(obj->window);
	sfFloatRect spriteRect;

	background.sprite = mh_init_sprite(SPRITE_BG);
	spriteRect = sfSprite_getGlobalBounds(background.sprite);

	mh_sprite_scaler(background.sprite, windowSize.x / spriteRect.width,
			 windowSize.y / spriteRect.height);
	return (background);
}

sfSprite *mh_init_cursor(struct s_mh_obj *obj)
{
	sfSprite *cursor = mh_init_sprite(SPRITE_CURSOR);

	sfRenderWindow_setMouseCursorVisible(obj->window, sfFalse);
	return (cursor);
}
