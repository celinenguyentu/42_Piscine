/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfischof <pfischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:51:45 by pfischof          #+#    #+#             */
/*   Updated: 2024/02/27 23:44:33 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

static int	valid_markers(char *markers)
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

static char	*first_row(char *board, char *markers)
{
	unsigned int	i;
	unsigned int	size;

	i = 0;
	size = 0;
	while (board[size] != '\n')
		size++;
	if (size < 3)
		return (NULL);
	while (i < 3)
	{
		markers[2 - i] = board[size - i - 1];
		i++;
	}
	if (!valid_markers(markers))
		return (NULL);
	while (size - i > 0)
	{
		if (!ft_is_digit(board[size - i - 1]))
			return (NULL);
		size--;
	}
	return (markers);
}

static int	valid_char(char c, char *markers)
{
	unsigned int	i;

	i = 0;
	while (i < 2)
	{
		if (c == markers[i])
			return (1);
		i++;
	}
	return (0);
}

static int	lines_number(char *nbr, unsigned int size)
{
	unsigned int	i;
	unsigned int	lines;

	i = 0;
	while (i < size)
	{
		lines = lines * 10 + nbr[i] - 48;
		i++;
	}
	return (lines);
}

static int	valid_map(char *map, char *markers, unsigned int lines)
{
	unsigned int	i;
	unsigned int	rows;
	unsigned int	line_length;

	i = 0;
	rows = 0;
	line_length = 0;
	while (map[i])
	{
		if (map[i] != '\n' && rows == 0)
			line_length++;
		else if (map[i] == '\n')
		{
			if ((i - rows) % line_length != 0 || rows > lines)
				return (0);
			rows++;
		}
	//	printf("rows = %d", rows);
		if (map[i] != '\n' && !valid_char(map[i], markers))
			return (0);
		i++;
	}
	if (((i - rows) % line_length != 0) || i < 1 || (rows != lines))
	{
		return (0);
	}
	return (1);
}

int	valid_board(char *board)
{
	unsigned int	size;
	unsigned int	lines;
	char			*markers;

	size = 0;
	markers = (char *)malloc(sizeof(char) * 4);
	if (!markers)
	{
		free(markers);
		return (0);
	}
	markers = first_row(board, markers);
	while (board[size] != '\n')
		size++;
	lines = lines_number(&board[0], size - 3);
	if (!markers || !valid_map(&board[size + 1], markers, lines))
	{
		free(markers);
		return (0);
	}
	return (1);
}
