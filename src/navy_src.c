/*
** EPITECH PROJECT, 2018
** navy_src.c
** File description:
** navy_src function
*/

#include "navy.h"

int my_atoi(char *str)
{
	int i = 0;
	int ret = 0;

	while (str[i]) {
		ret = (10 * ret) + str[i] - '0';
		i += 1;
	}
	return (ret);
}

void my_putnbr(int nb)
{
	if (nb < 0){
		nb *= -1;
		my_putchar('-');
	}
	if (nb > 9)
		my_putnbr(nb / 10);
	my_putchar(nb % 10 + '0');
}

int my_putstr(char *str)
{
	int i = 0;

	while (str[i]) {
		my_putchar(str[i]);
		i += 1;
	}
	return (0);
}

void my_putchar(char c)
{
	write(1, &c, 1);
}

char *my_strmcat(char *src1, char *src2)
{
	int i = 0;
	int j = 0;
	int len = 0;
	int malloc_size = my_strlen(src1) + my_strlen(src2) + 2;
	char *dest = malloc(sizeof(char) * malloc_size);

	while (src1[i]) {
		dest[len] = src1[i];
		i += 1;
		len += 1;
	}
	while (src2[j]) {
		dest[len] = src2[j];
		j += 1;
		len += 1;
	}
	dest[len] = '\0';
	return (dest);
}
