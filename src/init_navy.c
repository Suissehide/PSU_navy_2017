/*
** EPITECH PROJECT, 2018
** navy_wait.c
** File description:
** navy_wait function
*/

#include "navy.h"

void memclean(void *sig, int size)
{
	int i = 0;
	unsigned char *ptr = sig;

	while (i < size) {
		*ptr = 0;
		ptr += 1;
		i += 1;
	}
}

void init_sigaction(void)
{
	struct sigaction act;

	memclean(&act, sizeof(act));
	act.sa_sigaction = &receive_signal;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
}

int init_map(char *path)
{
	char *buf = malloc(sizeof(char) * 33);
	int fd = 0;

	if ((fd = open(path, O_RDONLY)) == -1)
		return (84);
	read(fd, buf, 33);
	if (player_pos(buf) == 84)
		return (84);
	return (0);
}

void init_navy(void)
{
	init_sigaction();
	NAVY.me.pid = getpid();
	NAVY.enemy.pid = 0;
	NAVY.receive_x = 0;
	NAVY.receive_y = 0;
	NAVY.receive_nbr = 0;
	NAVY.last = 0;
	NAVY.me.hit = 0;
	NAVY.enemy.hit = 0;
	create_board();
}
