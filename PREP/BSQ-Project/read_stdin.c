/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfischof <pfischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:16:28 by pfischof          #+#    #+#             */
/*   Updated: 2024/02/28 00:12:13 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

char	*read_stdin(void)
{
	int		i;
	char	buffer[1];
	char	*board;

	i = 0;
	board = (char *)malloc(sizeof(char) * 1);
	if (!board)
		return (NULL);
	board[0] = '\0';
	while (read(0, buffer, 1))
	{
		board = ft_realloc(board, 1);
		if (!board)
			return (NULL);
		board[i] = buffer[0];
		i++;
	}
	board = ft_realloc(board, 1);
	board[i] = '\0';
	return (board);
}

