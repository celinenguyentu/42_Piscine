/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 02:16:43 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/02/15 02:35:04 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int n)
{
	int	res;

	res = 1;
	if (n < 0)
		return (0);
	else
		while (n > 1)
		{
			res *= n;
			n--;
		}
	return (res);
}

	//TEST CASES
#include <stdio.h>

int	main(void)
{
	int	eg[] = {-3, 0, 1, 4, 12};

	for (int i=0; i<5; i++)
		printf("factorial %d : %d\n", eg[i], ft_iterative_factorial(eg[i]));
	return (0);
}
