/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 04:10:19 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/02/29 14:42:16 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*res;

	i = 0;
	res = malloc(length * sizeof(int));
	if (!res)
		return (NULL);
	while (i < length)
	{
		res[i] = f(tab[i]);
		i++;
	}
	return (res);
}

/*	//TEST CASES
#include <stdio.h>

int	is_even(int n)
{
	return (n % 2 == 0);
}

int	main(void)
{
	int	tab[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int	*res = ft_map(tab, 10, &is_even);

	for (int i = 0; i < 10; i++)
		printf("%d ", res[i]);
	return (0);
}
*/
