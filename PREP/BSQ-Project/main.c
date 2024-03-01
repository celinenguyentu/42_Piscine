/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:10:55 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/02/28 00:21:30 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	ft_putstr(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		board_nb;
	char	*board;

	board_nb = 1;
	if (argc > 1)
	{
		while (board_nb < argc)
		{
			board = read_file(argv[board_nb]);
			ft_putstr(board);
			if (valid_board(board))

		//		solver(board);
				write(1, "valid", 6);
			else
				write(2, "map error\n", 10);
		board_nb++;
		}
	}
	if (argc == 1)
	{
		board = read_stdin();
		ft_putstr(board);
		if (valid_board(board))
			write(1, "valid", 6);
	//		solver(board);
		else
			write(2, "map error\n", 10);
	}
	return (0);
}
