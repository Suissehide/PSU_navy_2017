/*
** EPITECH PROJECT, 2018
** navy_wait.c
** File description:
** navy_wait function
*/

#include "navy.h"

void wait_send(void)
{
	int i = 0;

	while (i < 100000 && NAVY.receive_nbr < 1) {
		usleep(10);
		i += 1;
	}
	NAVY.receive_nbr = 0;
	if (i >= 1000 || NAVY.last == 1)
		create_signal(NAVY.send_x, NAVY.send_y);
}

void navy_wait(void)
{
	NAVY.receive_nbr = 0;
	NAVY.wait = 0;
	NAVY.receive_x = 0;
	NAVY.receive_y = 0;
	while (NAVY.receive_nbr < 8) {
		if (NAVY.receive_nbr > 0 && NAVY.wait > 10000) {
			NAVY.receive_nbr = 0;
			NAVY.wait = 0;
			NAVY.receive_x = 0;
			NAVY.receive_y = 0;
			kill(NAVY.enemy.pid, SIGUSR2);
		}
		usleep(10);
		NAVY.wait += 1;
	}
	NAVY.receive_nbr = 0;
}
