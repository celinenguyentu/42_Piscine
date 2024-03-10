/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:43:37 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/03/10 04:02:37 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	in_range(int *tab, int n, int index, int value)
{
	if (index >= 0 && index < n)
	{
		if (value > tab[index - 1] || index == 0)
		{
			if (value < 9 - n + 1 + index)
				return (1);
			else if (value == 9 - n + 1 + index)
				return (2);
		}
	}
	return (0);
}

void	ft_print_tab(int *tab, int n)
{
	int	i;
	int	is_last;

	i = 0;
	is_last = 1;
	while (i < n)
	{
		ft_putchar(tab[i] + '0');
		if (in_range(tab, n, i, tab[i]) != 2)
			is_last = 0;
		i++;
	}
	if (!is_last)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

int	ft_print_combn_rec(int *tab, int n, int index)
{
	int	num;

	if (index >= n)
	{
		ft_print_tab(tab, n);
		return (0);
	}
	num = 0;
	while (num < 10)
	{
		if (in_range(tab, n, index, num))
		{
			tab[index] = num;
			if (ft_print_combn_rec(tab, n, index + 1) == 1)
				return (1);
			tab[index] = -1;
		}
		num++;
	}
	return (0);
}

void	ft_print_combn(int n)
{
	int	tab[10];
	int	i;

	i = 0;
	while (i < 10)
	{
		tab[i] = -1;
		i++;
	}
	ft_print_combn_rec(tab, n, 0);
}

/*	//TEST CASES
int	main(void)
{
	ft_print_combn(2);
	ft_print_combn(9);
	return (0);
}
*/