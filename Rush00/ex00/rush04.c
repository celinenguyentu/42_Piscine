/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:38:27 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/03/11 06:08:19 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_line(int x, char start, char middle, char end)
{
	int	columns;

	columns = 0;
	if (x >= 1)
	{
		ft_putchar(start);
		columns++;
	}
	while (columns++ < x - 1)
		ft_putchar(middle);
	if (x >= 2)
		ft_putchar(end);
	if (x > 0)
		ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	lines;

	lines = 0;
	if (y >= 1)
	{
		ft_print_line(x, 'A', 'B', 'C');
		lines++;
	}
	while (lines++ < y - 1)
		ft_print_line(x, 'B', ' ', 'B');
	if (y >= 2)
		ft_print_line(x, 'C', 'B', 'A');
}
