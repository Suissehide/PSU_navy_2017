/*
** EPITECH PROJECT, 2018
** navy.c
** File description:
** navy function
*/

#include "navy.h"

char *format_entry(char *str)
{
	int i = 0;
	char c;

	if (!str)
		return (str);
	while (str[i]) {
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i += 1;
	}
	if (str[0] >= '0' && str[0] <= '9') {
		c = str[0];
		str[0] = str[1];
		str[1] = c;
	}
	return (str);
}

int apply_hit(char *s)
{
	int x = s[1] - '1' + 2;
	int y = s[0] - 'A' + 2 + ((s[0] - 'A') * 2 / 2);

	if (NAVY.receive_x == 9 && NAVY.receive_y == 9) {
		if (NAVY.enemy.board[x][y] != 'x') {
			NAVY.enemy.board[x][y] = 'x';
			NAVY.enemy.hit += 1;
			return (1);
		}
	}
	else
		NAVY.enemy.board[x][y] = 'o';
	return (0);
}

int check_hit(void)
{
	int x = NAVY.receive_x + 2 + (NAVY.receive_x * 2) / 2;
	int y = NAVY.receive_y + 2;

	if (NAVY.me.board[y][x] != '.') {
		if (NAVY.me.board[y][x] != 'x') {
			display_result(1);
			NAVY.me.hit += 1;
		}
		else
			display_result(0);
		NAVY.me.board[y][x] = 'x';
		return (1);
	}
	else {
		display_result(0);
		NAVY.me.board[y][x] = 'o';
		return (0);
	}
}

int check_entry(char *s)
{
	if (!s)
		return (0);
	if (my_strlen(s) != 2) {
		my_putstr("wrong position\nattack: ");
		return (0);
	}
	if (s[0] >= 'A' && s[0] <= 'H' && s[1] >= '1' && s[1] <= '8')
		return (1);
	my_putstr("wrong position\nattack: ");
	return (0);
}
