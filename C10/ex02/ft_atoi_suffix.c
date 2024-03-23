/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_suffix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 00:10:56 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/03/23 00:11:03 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	map_get_index(char **keys, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	while (i < 19)
	{
		j = 0;
		while (to_find[j] && keys[i][j] == to_find[j])
			j++;
		if (!keys[i][j])
			return (i);
		i++;
	}
	return (-1);
}

int	map_get(char **keys, char *to_find, int *values)
{
	int	i;

	i = map_get_index(keys, to_find);
	if (i == -1)
		return (-1);
	else
		return (values[i]);
}

int	ft_atoi_suffix(char *str)
{
	int		idx;
	int		value;
	char	**suffixes;

	suffixes = (char *[19]){"B", "KB", "K", "MB", "M", "GB", "G", "TB",
		"T", "PB", "P", "EB", "E", "ZB", "Z", "YB", "Y", "RB", "R"};
	idx = 0;
	value = 0;
	while (str[idx] >= '0' && str[idx] <= '9')
		value = value * 10 + str[idx++] - '0';
	if (idx == 0)
		return (-1);
	if (str[idx] && map_get_index(suffixes, &str[idx]) == -1)
		return (-1);
	return (value);
}
