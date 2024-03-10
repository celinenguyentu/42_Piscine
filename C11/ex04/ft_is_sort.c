/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 04:35:55 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/03/10 19:33:51 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	inc;
	int	dec;

	i = 0;
	inc = 1;
	dec = 1;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			inc = 0;
		if (f(tab[i], tab[i + 1]) < 0)
			dec = 0;
		i++;
	}
	if (dec || inc)
		return (1);
	else
		return (0);
}

/*	//TEST CASES
#include <stdio.h>

int	greater(int a, int b)
{
	return (a - b);
}

int	main(void)
{
	int	tab1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int	tab2[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	int	tab3[10] = {1, 2, 3, 3, 4, 4, 5, 6, 8, 9};
	int	tab4[10] = {9, 2, 3, 1, 3, 9, 4, 2, 8, 2};

	printf("tab1 is sorted : %d\n", ft_is_sort(tab1, 10, greater));
	printf("tab2 is sorted : %d\n", ft_is_sort(tab2, 10, greater));
	printf("tab3 is sorted : %d\n", ft_is_sort(tab3, 10, greater));
	printf("tab4 is sorted : %d\n", ft_is_sort(tab4, 10, greater));
	return (0);
}
*/