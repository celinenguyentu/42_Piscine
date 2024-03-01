/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:38:36 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/02/28 00:03:46 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

char	*read_file(char *file_name)
{
	int		fd;
	char	buffer[1];
	int		bytes_read;
	char	*res;
	int		i;

	i = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (NULL);
	res = malloc(sizeof(char));
	if (!res)
		return (NULL);
	res[0] = '\0';
	bytes_read = -1;
	while (bytes_read != 0)
	{
		bytes_read = read(fd, buffer, 1);
		if (bytes_read == -1)
			return (NULL);
		res = ft_realloc(res, 1);
		if (!res)
			return (NULL);
		res[i] = buffer[0];
		i++;
	}
	res[i - 1] = '\0';
	if (close(fd) < 0)
		return (NULL);
	return (res);
}

void	print_board(t_board board, int view_intmap)
{
	int	i;
	int	j;

	i = 0;
	while (i < board.rows)
	{
		j = 0;
		while (j < board.cols)
		{
			ft_putchar(board.map[i][j]);
			j++;
		}
		if (view_intmap == 1)
		{
			ft_putchar(' ');
			while (j >= 0)
			{
				ft_putchar(board.intmap[i][board.cols - j]);
				j--;
			}
		}
		ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');
}

int	**create_intmap(char **map, int rows, int cols, char obs)
{
	int	**intmap;
	int	i;
	int	j;

	intmap = board_init(rows, cols);
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (map[i][j] == obs)
				intmap[i][j] = 1;
			if (i > 0)
				intmap[i][j] += intmap[i - 1][j];
			if (j > 0)
				intmap[i][j] += intmap[i][j - 1];
			if (i > 0 && j > 0)
				intmap[i][j] -= intmap[i - 1][j - 1];
			j++;
		}
		i++;
	}
	return (intmap);
}
