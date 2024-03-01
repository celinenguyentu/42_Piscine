/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:21:21 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/02/21 17:49:55 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	else if (index == 0)
		return (0);
	else if (index == 1)
		return (1);
	else
		return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

/*	//TEST CASES
#include <stdio.h>

int	main(void)
{
	int	n1 = 3;
	int	n2 = 7;
	int	n3 = 8;
	int	n4 = 15;

	printf("%d-ieme element of Fibonacci : %d\n", n1, ft_fibonacci(n1));
	printf("%d-ieme element of Fibonacci:  %d\n", n2, ft_fibonacci(n2));
	printf("%d-ieme element of Fibonacci:  %d\n", n3, ft_fibonacci(n3));
	printf("%d-ieme element of Fibonacci:  %d\n", n4, ft_fibonacci(n4));
	return (0);
}	
*/
