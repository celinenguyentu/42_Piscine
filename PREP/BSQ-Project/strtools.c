/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:36:01 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/02/27 22:45:47 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	**board_init(int rows, int cols)
{
	int	**board;
	int	i;
	int	j;

	i = 0;
	board = (int **)malloc(rows * sizeof(int *));
	while (i < rows)
	{
		board[i] = (int *)malloc(cols * sizeof(int));
		i++;
	}
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			board[i][j] = 0;
			j++;
		}
		i++;
	}
	return (board);
}
