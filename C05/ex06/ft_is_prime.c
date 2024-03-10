/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:20:14 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/03/10 17:05:28 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	long	i;

	if (nb == 2 || nb == 3)
		return (1);
	if (nb <= 1 || nb % 2 == 0 || nb % 3 == 0)
		return (0);
	i = 5;
	while (i * i <= nb)
	{
		if (nb % i == 0 || nb % (i + 2) == 0)
			return (0);
		i += 6;
	}
	return (1);
}

/*	//TEST CASES
#include <stdio.h>

int	main(void)
{
	int	n1 = 0;
	int	n2 = 706362023;
	int	n3 = 2147483647;
	int	n4 = 1;

	printf("%d is prime : %d\n", n1, ft_is_prime(n1));
	printf("%d is prime : %d\n", n2, ft_is_prime(n2));
	printf("%d is prime : %d\n", n3, ft_is_prime(n3));
	printf("%d is prime : %d\n", n4, ft_is_prime(n4));
	return (0);
}
*/