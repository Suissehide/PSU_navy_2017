/*
** EPITECH PROJECT, 2018
** navy_connection.c
** File description:
** navy_connection function
*/

#include "navy.h"

void check_victory(void)
{
	display_board();
	if (NAVY.me.hit >= 14)
		my_putstr("\nEnemy won\n");
	else if (NAVY.enemy.hit >= 14)
		my_putstr("\nI won\n");
}

void navy_server(void)
{
	my_putstr("my_pid: ");
	my_putnbr(NAVY.me.pid);
	my_putstr("\nwaiting for enemy connection...\n\n");
	navy_wait();
	my_putstr("enemy connected\n\n");
	display_board();
	game_server();
	check_victory();
}

void navy_client(void)
{
	create_signal(9, 9);
	my_putstr("my_pid: ");
	my_putnbr(NAVY.me.pid);
	my_putstr("\nsuccessfully connected\n\n");
	display_board();
	game_client();
	check_victory();
}
