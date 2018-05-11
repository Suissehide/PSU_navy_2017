/*
** EPITECH PROJECT, 2018
** game
** File description:
** game fct
*/

#include "navy.h"

void game_server(void)
{
	char *s;

	while (NAVY.me.hit < 14 && NAVY.enemy.hit < 14) {
		my_putstr("\nattack: ");
		while (check_entry(format_entry(s = get_next_line(0))) != 1);
		create_signal(s[0] - 'A', s[1] - '1');
		navy_wait();
		if (apply_hit(s))
			my_putstr(my_putstr(s) + ": hit\n\n");
		else
			my_putstr(my_putstr(s) + ": missed\n\n");
		if (NAVY.me.hit < 14 && NAVY.enemy.hit < 14) {
			my_putstr("waiting for enemy's attack...\n");
			navy_wait();
			if (check_hit())
				create_signal(9, 9);
			else
				create_signal(8, 8);
			display_board();
		}
	}
}

void game_client(void)
{
	char *s;

	while (NAVY.me.hit < 14 && NAVY.enemy.hit < 14) {
		my_putstr("\nwaiting for enemy's attack...\n");
		navy_wait();
		if (check_hit())
			create_signal(9, 9);
		else
			create_signal(8, 8);
		if (NAVY.me.hit < 14 && NAVY.enemy.hit < 14) {
			my_putstr("attack: ");
			while (check_entry(format_entry(s = get_next_line(0))) != 1);
			create_signal(s[0] - 'A', s[1] - '1');
			navy_wait();
			if (apply_hit(s))
				my_putstr(my_putstr(s) + ": hit\n\n");
			else
				my_putstr(my_putstr(s) + ": missed\n\n");
			display_board();
		}
	}
}
