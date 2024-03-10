/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 04:04:19 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/03/10 18:03:36 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	size;
	int	*tab;
	int	i;

	size = max - min;
	if (size > 0)
	{
		tab = malloc(size * sizeof(int));
		if (tab)
		{
			i = min;
			while (i < max)
			{
				tab[i - min] = i;
				i++;
			}
			return (tab);
		}
		else
			return (NULL);
	}
	else
		return (NULL);
}

/*	//TEST CASES
#include <stdio.h>

int	main(void)
{
	int	min = 18;
	int	max = 42;
	int	*array = ft_range(min, max);
	int	i;

	i = 0;
	while (i < max - min)
	{
		printf("%d ", array[i]);
		i++;
	}
	printf("\n");
	return (0);
}
*/