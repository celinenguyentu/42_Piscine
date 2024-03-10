/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 04:46:11 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/03/10 18:15:28 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	if (max <= min)
	{
		*range = NULL;
		return (0);
	}
	*range = malloc((max - min) * sizeof(int));
	if (!*range)
	{
		*range = NULL;
		return (-1);
	}
	i = min;
	while (i < max)
	{
		(*range)[i - min] = i;
		i++;
	}
	return (max - min);
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