/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:18:57 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/02/21 17:53:00 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	x0;
	int	x1;

	if (nb == 1)
		return (1);
	if (nb < 1)
		return (0);
	else
	{
		x0 = nb / 2;
		x1 = (x0 + nb / x0) / 2;
		while (x1 < x0)
		{
			x0 = x1;
			x1 = (x0 + nb / x0) / 2;
		}
		if (x0 * x0 == nb)
			return (x0);
		else
			return (0);
	}
}

/*	//TEST CASES
#include <stdio.h>
#include <math.h>

int	main(void)
{
	int	n1 = 54756;
	int	n2 = 2147395600;
	int	n3 = 250;
	int	n4 = -294;
	printf("sqrt(%d) = %d\n", n1, ft_sqrt(n1));
	printf("sqrt(%d) = %d\n", n2, ft_sqrt(n2));
	printf("sqrt(%d) = %d\n", n3, ft_sqrt(n3));
	printf("sqrt(%d) = %d\n", n4, ft_sqrt(n4));
	printf("sqrtOG(%d) = %f\n", n1, sqrt(n1));
	printf("sqrtOG(%d) = %f\n", n2, sqrt(n2));
	printf("sqrtOG(%d) = %f\n", n3, sqrt(n3));
	printf("sqrtOG(%d) = %f\n", n4, sqrt(n4));
	return (0);
}
*/
