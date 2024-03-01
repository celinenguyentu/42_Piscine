/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:02:23 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/02/08 14:13:19 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	tmp;

	if (*b != 0)
	{
		tmp = *a;
		*a = *a / *b;
		*b = tmp % *b;
	}
}

/*	//TEST CASES
#include <stdio.h>

int	main(void)
{
	int	a;
	int	b;

	a = 42;
	b = 18;
	printf("Before ft_ultimate_div_mod : a = %d, b = %d\n", a, b);
	ft_ultimate_div_mod(&a, &b);
	printf("After ft_ultimate_div_mod : a = %d, b = %d\n", a, b);
	return (0);
}
*/
