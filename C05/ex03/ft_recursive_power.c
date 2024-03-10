/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:09:17 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/03/10 17:01:54 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
		return (nb * ft_recursive_power(nb, power - 1));
}

/*	//TEST CASES
#include <stdio.h>

int	main(void)
{
	printf("pow(%d, %d) = %d\n", 3, -3, ft_recursive_power(3, -3));
	printf("pow(%d, %d) = %d\n", 0, 2, ft_recursive_power(0, 2));
	printf("pow(%d, %d) = %d\n", 0, 0, ft_recursive_power(0, 0));
	printf("pow(%d, %d) = %d\n", 2, 0, ft_recursive_power(2, 0));
	printf("pow(%d, %d) = %d\n", 4, 3, ft_recursive_power(4, 3));
	printf("pow(%d, %d) = %d\n", -4, 3, ft_recursive_power(-4, 3));
	return (0);
}
*/