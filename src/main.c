/*
** EPITECH PROJECT, 2018
** navy_wait.c
** File description:
** navy_wait function
*/

#include "navy.h"

int display_usage(void)
{
	my_putstr("USAGE\n\t./navy [first_player_pid] navy_positions");
	my_putstr("\nDESCRIPTION\n\tfirst_player_pid:  only for the ");
	my_putstr("2nd player.\n\tnavy_positions:  file representing");
	my_putstr(" the positions of the ships\n");
	return (0);
}

int main(int ac, char **av)
{
	if (ac < 2)
		return (84);
	if (av[1][0] == '-' && av[1][1] == 'h')
		return (display_usage());
	init_navy();
	if (ac == 2) {
		if (init_map(av[1]) == 84)
			return (84);
		navy_server();
	}
	if (ac == 3) {
		if (init_map(av[2]) == 84)
			return (84);
		NAVY.enemy.pid = my_atoi(av[1]);
		navy_client();
	}
	return (0);
}
