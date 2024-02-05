/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 21:18:56 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/02/02 22:01:22 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>

void	ft_print_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("%s", "\n");
}
*/

// tri par insertion
void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;
	int	j;

	i = 1;
	while (i < size)
	{
		tmp = tab[i];
		j = i;
		while (j > 0 && tab[j - 1] > tmp)
		{
			tab[j] = tab[j - 1];
			j--;
		}
		tab[j] = tmp;
		i++;
	}
}
/*
int	main(void)
{
	int	tab[8];

	tab[0] = 6;
	tab[1] = 5;
	tab[2] = 3;
	tab[3] = 1;
	tab[4] = 8;
	tab[5] = 7;
	tab[6] = 2;
	tab[7] = 4;
	ft_print_tab(tab, 8);
	ft_sort_int_tab(tab, 8);
	ft_print_tab(tab, 8);
	return (0);
}
*/
