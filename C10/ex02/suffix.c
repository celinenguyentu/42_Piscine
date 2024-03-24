/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suffix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 00:10:56 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/03/24 21:22:01 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}

int	get_sid(char *to_find)
{
	int		i;
	int		j;
	char	**suffixes;

	suffixes = (char *[19]){"B", "KB", "K", "MB", "M", "GB", "G", "TB",
		"T", "PB", "P", "EB", "E", "ZB", "Z", "YB", "Y", "RB", "R"};
	i = 0;
	while (i < 19)
	{
		j = 0;
		while (to_find[j] && suffixes[i][j] == to_find[j])
			j++;
		if (!suffixes[i][j])
			return (i);
		i++;
	}
	return (-1);
}

int	get_sval(char *to_find, int *values)
{
	int	i;

	i = get_sid(ft_strupcase(to_find));
	if (i == -1)
		return (-1);
	else
		return (values[i]);
}

int	mult_overflow(size_t n1, size_t n2)
{
	size_t	mul;

	mul = n1 * n2;
	if (n1 != 0 && mul / n1 != n2)
		return (1);
	else
		return (0);
}

size_t	mult_suffix(size_t size, char *to_find)
{
	int				*factor;
	int				*power;
	unsigned int	get_power;
	size_t			get_factor;
	unsigned int	i;

	factor = (int [19]){512, 1000, 1024, 1000, 1024, 1000, 1024, 1000,
		1024, 1000, 1024, 1000, 1024, 1000, 1024, 1000, 1024, 1000, 1024};
	power = (int [19]){1, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9};
	i = 0;
	get_factor = (size_t)get_sval(to_find, factor);
	get_power = (unsigned int)get_sval(to_find, power);
	while (i < get_power)
	{
		if (mult_overflow(size, get_factor))
			return ((size_t) - 1);
		size *= get_factor;
		i++;
	}
	return (size);
}
