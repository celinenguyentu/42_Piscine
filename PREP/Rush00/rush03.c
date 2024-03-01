/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:35:28 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/02/11 20:38:07 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_top(int x)
{
	int	columns;

	columns = 0;
	if (x >= 1)
	{
		ft_putchar('A');
		columns++;
	}
	while (columns < x - 1)
	{
		ft_putchar('B');
		columns++;
	}
	if (x >= 2)
	{
		ft_putchar('C');
	}
	ft_putchar('\n');
}

void	ft_print_lateral(int x)
{
	int	columns;

	columns = 0;
	if (x >= 1)
	{
		ft_putchar('B');
		columns++;
	}
	while (columns < x - 1)
	{
		ft_putchar(' ');
		columns++;
	}
	if (x >= 2)
	{
		ft_putchar('B');
	}
	ft_putchar('\n');
}

void	ft_print_bottom(int x)
{
	int	columns;

	columns = 0;
	if (x >= 1)
	{
		ft_putchar('A');
		columns++;
	}
	while (columns < x - 1)
	{
		ft_putchar('B');
		columns++;
	}
	if (x >= 2)
	{
		ft_putchar('C');
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	lines;

	lines = 0;
	if (y >= 1)
	{
		ft_print_top(x);
		lines++;
	}
	while (lines < y - 1)
	{
		ft_print_lateral(x);
		lines++;
	}
	if (y >= 2)
	{
		ft_print_bottom(x);
	}
}
