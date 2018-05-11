/*
** EPITECH PROJECT, 2018
** get_next_line.c
** File description:
** get_next_line function
*/

#include "get_next_line.h"

int my_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i += 1;
	return (i);
}

char *my_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	while (src[i] && i < n) {
		dest[i] = src[i];
		i += 1;
	}
	dest[i] = 0;
	return (dest);
}

static char *my_realloc(char *line, int i, char *buffer, int *cursor)
{
	int len;
	char *new_line;

	if (line != 0)
		len = my_strlen(line);
	else
		len = 0;
	if (!(new_line = malloc(sizeof(char) * (len + i + 1))))
		return (NULL);
	if (line != 0)
		my_strncpy(new_line, line, len);
	else
		my_strncpy(new_line, "", len);
	my_strncpy(new_line + len, buffer + *cursor, i);
	if (line)
		free(line);
	*cursor += i + 1;
	return (new_line);
}

char *get_next_line(int fd)
{
	char *line = 0;
	int i = 0;
	static char buffer[READ_SIZE];
	static int cursor = 0;
	static int size_buff = 0;

	while (42) {
		if (size_buff <= cursor) {
			i = 0;
			cursor = 0;
			if (!(size_buff = read(fd, buffer, READ_SIZE)))
				return (line);
			if (size_buff == -1)
				return (NULL);
		}
		if (buffer[cursor + i] == '\n')
			return (line = my_realloc(line, i, buffer, &cursor));
		if (cursor + i == size_buff - 1)
			line = my_realloc(line, i + 1, buffer, &cursor);
		i += 1;
	}
}
