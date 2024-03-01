/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:57:36 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/02/02 19:16:10 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(char *a1, char *a2, char *b1, char *b2)
{
	write(1, a1, 1);
	write(1, a2, 1);
	write(1, " ", 1);
	write(1, b1, 1);
	write(1, b2, 1);
	if (!(*a1 == '9' && *a2 == '8'))
		write(1, ", ", 2);
}

void	ft_increment(char *a1, char *a2)
{
	if (*a2 == '9')
	{
		(*a1)++;
		*a2 = '0';
	}
	else
		(*a2)++;
}

void	ft_print_comb2(void)
{
	char	a1;
	char	a2;
	char	b1;
	char	b2;

	a1 = '0';
	a2 = '0';
	while (!(a1 == '9' && a2 == '9'))
	{
		b1 = a1;
		b2 = a2;
		ft_increment(&b1, &b2);
		while (b1 <= '9' && b2 <= '9')
		{
			ft_print_numbers(&a1, &a2, &b1, &b2);
			ft_increment(&b1, &b2);
		}
		ft_increment(&a1, &a2);
	}
}

/*
int	main(void)
{
	ft_print_comb2();
	return (0);
}
*/
