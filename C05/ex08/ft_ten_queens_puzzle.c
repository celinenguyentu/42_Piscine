/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:22:14 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/03/10 17:11:19 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define SIZE 10

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_board(int *board)
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		ft_putchar(board[i] + '0');
		i++;
	}
	ft_putchar('\n');
}

int	is_safe(int *board, int col, int row)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (board[i] == row)
			return (0);
		if (board[i] == row - (col - i))
			return (0);
		if (board[i] == row + (col - i))
			return (0);
		i++;
	}
	return (1);
}

int	solver(int *board, int col, int *solutions)
{
	int	row;

	if (col >= SIZE)
	{
		(*solutions)++;
		print_board(board);
		return (0);
	}
	row = 0;
	while (row < SIZE)
	{
		if (is_safe(board, col, row) == 1)
		{
			board[col] = row;
			if (solver(board, col + 1, solutions) == 1)
				return (1);
			board[col] = -1;
		}
		row++;
	}
	return (0);
}

int	ft_ten_queens_puzzle(void)
{
	int	board[SIZE];
	int	solutions;
	int	i;

	i = 0;
	solutions = 0;
	while (i < SIZE)
	{
		board[i] = -1;
		i++;
	}
	solver(board, 0, &solutions);
	return (solutions);
}

/*	//TEST CASES
#include <stdio.h>

int	main(void)
{
	printf("Solutions des %d Dames : %d\n", SIZE, ft_ten_queens_puzzle());
	return (0);
}
*/