/*
** EPITECH PROJECT, 2018
** navy.c
** File description:
** navy function
*/

#include "navy.h"

char **create_first_board(char **board)
{
	board[0] = " |A B C D E F G H";
	board[1] = "-+---------------";
	board[2] = "1|. . . . . . . .";
	board[3] = "2|. . . . . . . .";
	board[4] = "3|. . . . . . . .";
	board[5] = "4|. . . . . . . .";
	board[6] = "5|. . . . . . . .";
	board[7] = "6|. . . . . . . .";
	board[8] = "7|. . . . . . . .";
	board[9] = "8|. . . . . . . .";
	return (board);
}

void copy_board(char **board, int i)
{
	int j = 0;

	while (j < 17) {
		NAVY.me.board[i][j] = board[i][j];
		NAVY.enemy.board[i][j] = board[i][j];
		j += 1;
	}
}

void create_board(void)
{
	int i = 0;
	char **board = malloc(sizeof(char *) * 10);

	board = create_first_board(board);
	while (i < 10) {
		copy_board(board, i);
		i += 1;
	}
	free(board);
}

void display_board(void)
{
	int i = 0;

	my_putstr("my positions:\n");
	while (i < 10) {
		my_putstr(NAVY.me.board[i]);
		my_putstr("\n");
		i += 1;
	}
	i = 0;
	my_putstr("\nenemy's positions:\n");
	while (i < 10) {
		my_putstr(NAVY.enemy.board[i]);
		my_putstr("\n");
		i += 1;
	}
}

void display_result(int hit)
{
	my_putchar(NAVY.receive_x + 'A');
	my_putchar(NAVY.receive_y + '1');
	if (hit)
		my_putstr(": hit\n\n");
	else
		my_putstr(": missed\n\n");
}
