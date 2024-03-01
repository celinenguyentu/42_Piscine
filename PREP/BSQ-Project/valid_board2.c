/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_board2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfischof <pfischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 21:13:32 by pfischof          #+#    #+#             */
/*   Updated: 2024/02/27 21:27:30 by pfischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

int	ft_is_printable(char c)
{
	return (c >= 32 && c <= 126);
}

int	ft_is_digit(char c)
{
	return (c >= 48 && c <= 57);
}

int	valid_markers(char *markers)
{
	unsigned int	i;

	i = 0;
	while (i < 3)
	{
		if (!ft_is_printable(markers[i]))
			return (0);
		i++;
	}
	if (markers[0] == markers[1] || markers[0] == markers[2]
		|| markers[1] == markers[0] || markers[1] == markers[2])
		return (0);
	return (1);
}
