/*
** EPITECH PROJECT, 2018
** navy_src.c
** File description:
** navy_src function
*/

#include "navy.h"

int power_rec(int nb, int p)
{
	if (p > 0)
		return (nb * power_rec(nb, p - 1));
	if (p == 0)
		return (1);
	else
		return (0);
}

int calc_int_length(int nb)
{
	int i = 0;

	while (nb > 0) {
		nb /= 10;
		i += 1;
	}
	return (i);
}

char *int_to_str(int nb)
{
	int length = calc_int_length(nb);
	char *str = malloc(sizeof(char) * (length + 2));
	int i = 0;

	if (!str)
		return (NULL);
	while (length > 0) {
		str[i] = (nb / power_rec(10, length - 1)) % 10 + '0';
		length -= 1;
		i += 1;
	}
	if (i == 0) {
		str[i] = '0';
		i += 1;
	}
	str[i] = '\0';
	return (str);
}

void my_swap(char *a, char *b)
{
	char tmp = *a;

	*a = *b;
	*b = tmp;
}

char	*my_revstr(char *str)
{
	int len = 0;
	int i = 0;
	int j = 0;

	while (str[len] != '\0')
		len += 1;
	j = len - 1;
	while (j > i) {
		my_swap(&str[j], &str[i]);
		i += 1;
		j -= 1;
	}
	return (str);
}
