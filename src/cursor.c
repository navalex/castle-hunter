/*
** EPITECH PROJECT, 2017
** Cursor
** File description:
** Cursor Manager
*/

#include "hunter.h"

void mh_cursor_draw(struct s_mh_obj *obj)
{
	sfVector2i mousePos = sfMouse_getPositionRenderWindow(obj->window);
	sfVector2f cursorPos;
	sfIntRect cursorRect = sfSprite_getTextureRect(obj->cursor);

	cursorPos.x = mousePos.x - (cursorRect.width / 2);
	cursorPos.y = mousePos.y - (cursorRect.height / 2);
	sfSprite_setPosition(obj->cursor, cursorPos);
	sfRenderWindow_drawSprite(obj->window, obj->cursor, NULL);
}
