/*
** EPITECH PROJECT, 2018
** navy_wait.c
** File description:
** navy_wait function
*/

#include "navy.h"

int verif_pos(char *buf)
{
	int i = 1;
	int j = 4;

	if (my_strlen(buf) < 32)
		return (84);
	while (i < 32) {
		if (buf[i] != ':' || buf[j] != ':')
			return (84);
		i += 8;
		j += 8;
	}
	if (buf[0] + buf[8] + buf[16] + buf[24] != 206)
		return (84);
	i = 2;
	j = 3;
	while (i < 31) {
		if (buf[i] != buf[i + 3] && buf[j] != buf[j + 3])
			return (84);
		i += 8;
		j += 8;
	}
	return (0);
}

int letter_pos(char *buf, int i)
{
	switch (buf[i + 2]) {
		case 65:
			return (2);
			break;
		case 66:
			return (4);
			break;
		case 67:
			return (6);
			break;
		case 68:
			return (8);
			break;
		case 69:
			return (10);
			break;
		case 70:
			return (12);
			break;
		case 71:
			return (14);
			break;
		case 72:
			return (16);
			break;
	}
	return (0);
}

void ship_same_letter(char *buf, int i)
{
	int nb_ship = buf[i] - 48;
	int go = 1;
	int letter = 0;

	while (go < nb_ship) {
		letter = letter_pos(buf, i);
		NAVY.me.board[buf[i + 3] - 47 + go][letter] = buf[i];
		go += 1;
	}
}

void ship_same_number(char *buf, int i)
{
	int nb_ship = buf[i] - 48;
	int go = 2;
	int letter = 0;

	while (go < nb_ship * 2) {
		letter = letter_pos(buf, i);
		NAVY.me.board[buf[i + 3] - 47][letter + go] = buf[i];
		go += 2;
	}
}

int player_pos(char *buf)
{
	int i = 0;

	if (verif_pos(buf) == 84)
		return (84);
	while (i < 32) {
		NAVY.me.board[buf[i + 3] - 47][letter_pos(buf, i)] = buf[i];
		i += 8;
	}
	i = 0;
	while (i < 31) {
		if (buf[i + 2] == buf[i + 5])
			ship_same_letter(buf, i);
		else
			ship_same_number(buf, i);
		i += 8;
	}
	if (verif_enough_boat() == 84)
		return (84);
	return (0);
}
