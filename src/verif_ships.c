/*
** EPITECH PROJECT, 2018
** navy
** File description:
** verif ships
*/

#include "navy.h"

int verif_enough_boat(void)
{
	int line = 2;
	int row = 0;
	int boat = 0;

	while (line != 9 || row != 18) {
		if (row == 18) {
			row = 0;
			line += 1;
		}
		if (NAVY.me.board[line][row] > 48	\
		&& NAVY.me.board[line][row] < 57)
			boat += NAVY.me.board[line][row] - 48;
		row += 2;
	}
	if (boat != 90)
		return (84);
	else
		return (0);
}
