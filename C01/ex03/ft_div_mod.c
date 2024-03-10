/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:47:46 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/03/10 04:49:50 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	if (b != 0)
	{
		*div = a / b;
		*mod = a % b;
	}
}

/*	//TEST CASES
#include <stdio.h>

int	main(void)
{
	int	a;
	int	b;
	int	div;
	int	mod;

	a = 42;
	b = 18;
	ft_div_mod(a, b, &div, &mod);
	printf("For a = %d and b = %d : div = %d and mod = %d\n", a, b, div, mod);
	return (0);
}
*/