/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:43:37 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/02/26 11:29:30 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_tab(int *tab, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_putchar(tab[i] + '0');
		ft_putchar(' ');
		i++;
	}	
}

int	in_range(int *tab, int n, int index, int value)
{
	if (index >= 0 && index < n)
		if (value <= 9 - n + 1 + index && value > tab[index - 1])
			return (1);
	return (0);
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
	while (num < n)
	{
		if (in_range(tab, n, index, num) == 1)
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


#include <stdio.h>

int	main(void)
{
	ft_print_combn(1);
//	ft_print_combn(2);
	//ft_print_combn(5);

	return (0);
}

//n = 3 max = 789
//012 013 014 015 ... 019 
//023 024 ... 029 
//034 ... 039 
//...
//078 079
//089 
//123 124 ... 129 
//134 ... 139
//178 179
//189
//234 ... 239
//...
//289
//...
//678 679
//689
//789






//n = 4 - 0123 0124 0125 ... 0129 0134 ... 6789
