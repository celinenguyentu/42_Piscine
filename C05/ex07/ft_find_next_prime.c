/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:21:17 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/03/10 17:07:50 by cnguyen-         ###   ########.fr       */
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

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	while (!ft_is_prime(nb))
		nb++;
	return (nb);
}

/*	//TEST CASES
#include <stdio.h>

int	main(void)
{
	int	n1 = -23;
	int	n2 = 2147483647;
	int	n3 = 3;
	int	n4 = 283792;

	printf("Next prime after %d is %d\n", n1, ft_find_next_prime(n1));
	printf("Next prime after %d is %d\n", n2, ft_find_next_prime(n2));
	printf("Next prime after %d is %d\n", n3, ft_find_next_prime(n3));
	printf("Next prime after %d is %d\n", n4, ft_find_next_prime(n4));
	return (0);
}
*/