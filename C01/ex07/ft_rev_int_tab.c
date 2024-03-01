/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:45:56 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/02/08 14:55:59 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size / 2)
	{
		tmp = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = tmp;
		i++;
	}
}

/*	//TEST CASES
#include <stdio.h>

int	main(void)
{
	int	tab[10];

	for (int i=0; i<10; i++) tab[i] = 13 + i * 2;
	printf("Before ft_rev_int_tab : ");
	for (int i=0; i<10; i++) printf("%d ", tab[i]);
	ft_rev_int_tab(tab, 10);
	printf("\nAfter fr_rev_int_tab : ");
	for (int i=0; i<10; i++) printf("%d ", tab[i]);
	printf("\n");
	return (0);
}
*/
