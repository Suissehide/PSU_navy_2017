/*
** EPITECH PROJECT, 2018
** navy_convert.c
** File description:
** navy_convert function
*/

#include "navy.h"

int	is_inbase(char c, char *base)
{
	int i = 0;

	while (base[i] != '\0' && base[i] != c)
		i += 1;
	return (base[i] != '\0');
}

int	getnbr_len(char *str, char *base, int start)
{
	int len = 0;

	while (is_inbase(str[start], base)) {
		len += 1;
		start += 1;
	}
	return (len);
}

int	get_base_ind(char c, char *base)
{
	int i = 0;

	while (base[i] != '\0') {
		if (base[i] == c)
			return (i);
		i += 1;
	}
	return (-1);
}

int	my_getnbr_base(char *str, char *base)
{
	int nb_moins = 0;
	int i = 0;
	int len_nb = 0;
	int final_nb = 0;
	int power = 1;
	int base_len = my_strlen(base);

	while (str[i] == '+' || str[i] == '-') {
		if (str[i] == '-')
			nb_moins += 1;
		i += 1;
	}
	len_nb = getnbr_len(str, base, i);
	i += len_nb - 1;
	while (len_nb > 0) {
		final_nb -= get_base_ind(str[i], base) * power;
		if (final_nb > 0)
			return (0);
		power = power * base_len;
		len_nb -= 1;
		i -= 1;
	}
	if (nb_moins % 2 == 0) {
		final_nb = -final_nb;
		if (final_nb < 0)
			return (0);
	}
	return (final_nb);
}

char	*convert_base(char *nbr, char *base_from, char *base_to)
{
	char *tab;
	int i = 0;
	int size = my_strlen(base_to);
	int number;

	tab = malloc(sizeof(char) * 300);
	number = my_getnbr_base(nbr, base_from);
	while (number > 0) {
		tab[i] = base_to[number % size];
		number = number / size;
		i += 1;
	}
	tab[i] = '\0';
	tab = my_revstr(tab);
	return (tab);
}
