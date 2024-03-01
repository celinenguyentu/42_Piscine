/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 20:53:11 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/02/02 21:17:47 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

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

/*
int	main(void)
{
	int	tab[10];

	for (int i=0; i<10; i++) tab[i] = 13+i;
	for (int i=0; i<10; i++) printf("%d ", tab[i]);
	ft_rev_int_tab(tab, 10);
	for (int i=0; i<10; i++) printf("%d ", tab[i]);
	return (0);
}
*/
