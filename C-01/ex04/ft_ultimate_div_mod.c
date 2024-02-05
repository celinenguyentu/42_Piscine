/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 20:19:01 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/02/02 22:26:33 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

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

/*
int	main(void)
{
	int	a;
	int	b;

	a = 42;
	b = 18;
	ft_ultimate_div_mod(&a, &b);
	printf("div %d, mod %d", a, b);
	return (0);
}
*/
