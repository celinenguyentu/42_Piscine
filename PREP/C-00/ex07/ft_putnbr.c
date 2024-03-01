/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 03:45:49 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/02/02 14:12:35 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int	n;

	n = nb;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		n %= 10;
	}
	ft_putchar(n + '0');
}

/*
int	main(void)
{
	ft_putnbr(0003);
	write(1, " ", 1);
	ft_putnbr(13846294);
	write(1, " ", 1);
	ft_putnbr(-3947274);
	write(1, " ", 1);
	ft_putnbr(-2147483647);
	return (0);
}
*/
