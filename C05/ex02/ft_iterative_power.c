/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 02:48:36 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/03/10 17:01:41 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	res;

	res = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power > 0)
	{
		res *= nb;
		power--;
	}
	return (res);
}

/*	//TEST CASES
#include <stdio.h>

int	main(void)
{
	printf("pow(%d, %d) = %d\n", 3, -3, ft_iterative_power(3, -3));
	printf("pow(%d, %d) = %d\n", 0, 2, ft_iterative_power(0, 2));
	printf("pow(%d, %d) = %d\n", 0, 0, ft_iterative_power(0, 0));
	printf("pow(%d, %d) = %d\n", 2, 0, ft_iterative_power(2, 0));
	printf("pow(%d, %d) = %d\n", 4, 3, ft_iterative_power(4, 3));
	printf("pow(%d, %d) = %d\n", -4, 3, ft_iterative_power(-4, 3));
	return (0);
}
*/