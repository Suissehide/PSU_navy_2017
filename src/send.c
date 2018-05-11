/*
** EPITECH PROJECT, 2018
** navy_wait.c
** File description:
** navy_wait function
*/

#include "navy.h"

int send_signal(char *str)
{
	int i = 0;

	while (str[i]) {
		if (str[i] == '0')
			kill(NAVY.enemy.pid, SIGUSR1);
		else if (str[i] == '1')
			kill(NAVY.enemy.pid, SIGUSR2);
		usleep(100);
		i += 1;
	}
	return (0);
}

char *create_bin(int nb)
{
	char *str = convert_base(int_to_str(nb), "0123456789", "01");
	char *fill_str = malloc(sizeof(char) * 9);
	int i = 0;
	int j = 0;

	if (!fill_str)
		return (NULL);
	while (i < 4 - my_strlen(str)) {
		fill_str[i] = '0';
		i += 1;
	}
	while (str[j]) {
		fill_str[i] = str[j];
		i += 1;
		j += 1;
	}
	fill_str[i] = '\0';
	free(str);
	return (fill_str);
}

void create_signal(int x, int y)
{
	char *bin_x = create_bin(x);
	char *bin_y = create_bin(y);

	NAVY.send_x = x;
	NAVY.send_y = y;
	while (send_signal(my_strmcat(bin_x, bin_y)) == -1);
	wait_send();
}
