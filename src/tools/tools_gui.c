/*
** EPITECH PROJECT, 2017
** Tools GUI
** File description:
** Graphical User Interface tools
*/

#include <SFML/Graphics/Rect.h>
#include "hunter.h"

void mh_gui_set_title(struct s_mh_obj *obj, char *str)
{
	sfFloatRect textRect;
	sfFloatRect menuRect;
	sfVector2f textPosition;

	sfText_setString(obj->ui.title, str);
	sfText_setColor(obj->ui.title, sfColor_fromRGB(160, 82, 45));
	textRect = sfText_getGlobalBounds(obj->ui.title);
	menuRect = sfSprite_getGlobalBounds(obj->ui.wrapper);
	textPosition.x = menuRect.left +
		((menuRect.width / 2) - (textRect.width / 2));
	textPosition.y = menuRect.top;
	sfText_setPosition(obj->ui.title, textPosition);
}

void mh_gui_btn_rect(sfSprite *btn, int state)
{
	sfIntRect rect = sfSprite_getTextureRect(btn);
	int left = 175;

	switch (state)
	{
		case 0:
			rect.left = left;
			break;
		case 1:
			rect.left = left + rect.width + 20;
			break;
		case 2:
			rect.left = left + (rect.width * 2) + 40;
			break;
	}
	sfSprite_setTextureRect(btn, rect);
}

void mh_gui_btn_text_place(struct s_mh_ui_btn *btn, sfFloatRect btnRect)
{
	sfFloatRect textRect = sfText_getGlobalBounds(btn->text);
	sfVector2f textPosition;

	textPosition.x = btnRect.left +
		((btnRect.width / 2) - (textRect.width / 2));
	textPosition.y = btnRect.top +
		(btnRect.height / 2) - (textRect.height);
	sfText_setColor(btn->text, sfColor_fromRGB(160, 82, 45));
	sfText_setPosition(btn->text, textPosition);
}

void mh_gui_btn_place(struct s_mh_obj *obj)
{
	sfFloatRect menuRect = sfSprite_getGlobalBounds(obj->ui.wrapper);
	sfFloatRect btnRect;
	sfVector2f btnPosition;
	float topBtn = menuRect.top + 200;
	int i = 0;

	while (i < GUI_BTN_NB) {
		btnRect = sfSprite_getGlobalBounds(obj->ui.btns[i].sprite);
		btnPosition.x = menuRect.left +
			((menuRect.width / 2) - (btnRect.width / 2));
		btnPosition.y = topBtn;
		sfSprite_setPosition(obj->ui.btns[i].sprite, btnPosition);
		mh_gui_btn_text_place(&obj->ui.btns[i], btnRect);
		sfRenderWindow_drawSprite(obj->window,
					  obj->ui.btns[i].sprite, NULL);
		sfRenderWindow_drawText(obj->window,
					obj->ui.btns[i].text, NULL);
		topBtn += btnRect.height + 20;
		i++;
	}
}

struct s_mh_ui_btn mh_gui_btn_create(char *name, int code)
{
	struct s_mh_ui_btn btn;

	btn.sprite = mh_init_sprite(SPRITE_UI_BUTTON);
	btn.text = mh_init_gui_text(name, 40);
	btn.code = code;
	mh_sprite_set_rect(btn.sprite, 175, 200, 365, 180);
	mh_sprite_scaler(btn.sprite, 1, 0.7);
	return (btn);
}
