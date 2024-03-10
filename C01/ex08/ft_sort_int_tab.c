/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:58:32 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/03/10 04:56:50 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/*	//TEST CASES
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
	printf("Before ft_sort_int_tab : ");
	ft_print_tab(tab, 8);
	ft_sort_int_tab(tab, 8);
	printf("After ft_sort_int_tab :");
	ft_print_tab(tab, 8);
	return (0);
}
*/