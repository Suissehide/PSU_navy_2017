/*
** EPITECH PROJECT, 2018
** receive.c
** File description:
** receive function
*/

#include "navy.h"

void transform_signal(int bit)
{
	if (NAVY.receive_nbr < 4) {
		if (NAVY.receive_nbr == 0)
			NAVY.receive_x = bit;
		else
			NAVY.receive_x = (NAVY.receive_x << 1) | bit;
	}
	else if (NAVY.receive_nbr < 8) {
		if (NAVY.receive_nbr == 4)
			NAVY.receive_y = bit;
		else
			NAVY.receive_y = (NAVY.receive_y << 1) | bit;
	}
}

void receive_signal(int sig, siginfo_t *siginfo, void *context)
{
	if (NAVY.enemy.pid == 0)
		NAVY.enemy.pid = siginfo->si_pid;
	else if (NAVY.enemy.pid != siginfo->si_pid)
		return;
	NAVY.wait = 0;
	NAVY.last = (sig == SIGUSR1) ? 0 : 1;
	transform_signal(NAVY.last);
	NAVY.receive_nbr += 1;
	if (NAVY.receive_nbr == 8) {
		usleep(5000);
		kill(NAVY.enemy.pid, SIGUSR1);
	}
	if (NAVY.receive_nbr > 16)
		NAVY.receive_nbr = 0;
}
