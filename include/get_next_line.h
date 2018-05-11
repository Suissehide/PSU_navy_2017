/*
** EPITECH PROJECT, 2017
** get_next_line.h
** File description:
** header files
*/

#ifndef MY_EXEC_H_
#define MY_EXEC_H_

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#ifndef READ_SIZE
	#define READ_SIZE (50)
#endif /* READ_SIZE */

char *get_next_line(int);

#endif /* MY_EXEC_H_ */
