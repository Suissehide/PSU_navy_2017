/*
** EPITECH PROJECT, 2018
** navy.h
** File description:
** header files
*/

#ifndef NAVY_H_
#define NAVY_H_

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"

#define NAVY t_navy

typedef struct s_player
{
	char board[10][18];
	pid_t pid;
	int hit;
} t_player;

struct s_navy
{
	t_player me;
	t_player enemy;
	char receive_x;
	char receive_y;
	int send_x;
	int send_y;
	int receive_nbr;
	int last;
	long wait;
} t_navy;

void init_navy();
int init_map(char *);
int player_pos(char *);
void create_board();
void display_board();
void display_result();

void create_signal(int, int);
void receive_signal(int, siginfo_t *, void *);

/* CONNECTION */
void navy_server();
void navy_client();

char *format_entry(char *str);
int apply_hit(char *s);
int check_hit(void);
int check_entry(char *s);
void game_server();
void game_client();

int verif_enough_boat(void);

/* WAIT */
void wait_send();
void navy_wait();

/* SRC */
int my_atoi(char *);
int my_putstr(char *);
void my_putchar(char);
void my_putnbr(int);
char *my_strmcat(char *, char *);
int my_strlen(char *);
char *int_to_str(int);
char *convert_base(char *, char *, char *);
char *my_revstr(char *);

#endif /* NAVY_H_ */
