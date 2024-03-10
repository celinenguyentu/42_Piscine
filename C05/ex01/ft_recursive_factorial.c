/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 02:36:14 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/03/10 17:01:36 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	else
		return (nb * ft_recursive_factorial(nb - 1));
}

/*	//TEST CASES
#include <stdio.h>

int	main(void)
{
	int	eg[] = {-3, 0, 1, 4, 128374};

	for (int i=0; i<5; i++)
		printf("factorial %d : %d\n", eg[i], ft_recursive_factorial(eg[i]));
	return (0);
}
*/