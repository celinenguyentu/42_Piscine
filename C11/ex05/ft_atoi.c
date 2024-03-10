/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 21:08:12 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/02/29 17:14:21 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_is_whitespace(char c)
{
	char	*whitespace;

	whitespace = " \f\n\r\t\v";
	while (*whitespace)
	{
		if (c == *whitespace)
			return (1);
		whitespace++;
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	i;
	int	number;

	i = 0;
	sign = 1;
	number = 0;
	while (str[i] != '\0' && ft_is_whitespace(str[i]))
		i++;
	while (str[i] != '\0' && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		number *= 10;
		number += str[i] - '0';
		i++;
	}
	return (sign * number);
}

/*	//TEST CASES
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	char	*nbr1 = " -+++- 1837ei821";
	char	*nbr2 = " \t--+--+0092823d8";
	char	*nbr3 = "923- -34s";
	char	*nbr4 = "12  48f";
	char	*nbr5 = "";
	char	*nbr6 = "2147483648";

	printf("atoi : %d\n", atoi(nbr1));
	printf("ft_atoi : %d\n", ft_atoi(nbr1));
	printf("atoi : %d\n", atoi(nbr2));
	printf("ft_atoi : %d\n", ft_atoi(nbr2));
	printf("atoi : %d\n", atoi(nbr3));
	printf("ft_atoi : %d\n", ft_atoi(nbr3));
	printf("atoi : %d\n", atoi(nbr4));
	printf("ft_atoi : %d\n", ft_atoi(nbr4));
	printf("atoi : %d\n", atoi(nbr5));
	printf("ft_atoi : %d\n", ft_atoi(nbr5));
	printf("atoi : %d\n", atoi(nbr6));
	printf("ft_atoi : %d\n", ft_atoi(nbr6));
	return (0);
}
*/
