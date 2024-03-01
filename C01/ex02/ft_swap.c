/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:37:56 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/02/08 13:44:22 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/*	//TEST CASES
#include <stdio.h>

int	main(void)
{
	int	a;
	int	b;

	a = 18;
	b = 42;
	printf("Before ft_swap : a = %d, b = %d\n", a, b);
	ft_swap(&a,&b);
	printf("After ft_swap : a = %d, b = %d\n", a, b);
	return (0);
}
*/
