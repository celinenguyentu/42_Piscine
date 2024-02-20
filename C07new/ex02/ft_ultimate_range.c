/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 04:46:11 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/02/20 11:57:04 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	i;

	size = max - min;
	if (size <= 0)
	{
		*range = NULL;
		return (0);
	}
	else
	{
		*range = malloc(size * sizeof(int));
		if (*range)
		{
			i = min;
			while (i < max)
			{
				(*range)[i - min] = i;
				i++;
			}
			return (size);
		}
		else
			return (-1);
	}
}

/*	//TEST CASES
#include <stdio.h>

int	main(void)
{
	int	*range;
	int	min;
	int	max;
	int	i;

	i = 0;
	min = 18;
	max = 42;
	printf("Range size : %d\n", ft_ultimate_range(&range, min, max));
	while (i < (max - min))
	{
		printf("%d ", range[i]);
		i++;
	}
	return (0);
}
*/
