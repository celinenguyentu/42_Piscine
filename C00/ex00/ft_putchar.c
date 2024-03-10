/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 06:30:33 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/03/10 03:37:17 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/*	//TEST CASES
int	main(void)
{
	ft_putchar('S');
	ft_putchar('c');
	ft_putchar('8');
	ft_putchar('\n');
	ft_putchar(65);
	return (0);
}
*/