/*
** EPITECH PROJECT, 2017
** Tools Global
** File description:
** Global game tools
*/

#include "hunter.h"

int mh_rand(int a, int b)
{
	return (rand() % (b - a) + a);
}

void mh_putstr(char *str)
{
	int i = 0;

	while (str[i]) {
		write(1, &str[i++], 1);
	}
}

char *mh_itoa(int nb, char *res)
{
	char *p = res;
	int temp;

	if (nb < 0) {
		*p++ = '-';
		nb *= (-1);
	}
	temp = nb;
	while (temp) {
		++p;
		temp /= 10;
	}
	*p = '\0';
	while (nb) {
		*--p = (char)(nb % 10 + '0');
		nb = nb / 10;
	}
	return (res);
}
