/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:51:33 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/02/02 20:02:23 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/*
int	main(void)
{
	int	a;
	int	b;
	int	*p;
	int	*q;

	a = 18;
	b = 42;
	p = &a;
	q = &b;
	ft_swap(p, q);
	printf("%d, %d", a, b);
	return (0);
}
*/
