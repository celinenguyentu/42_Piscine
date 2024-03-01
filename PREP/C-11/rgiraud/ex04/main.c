/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 08:22:36 by rgiraud           #+#    #+#             */
/*   Updated: 2023/08/23 08:30:15 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/ft.h"

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	value;

	i = 0;
	value = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		value = value * 10 + str[i] - '0';
		i++;
	}
	return (value * sign);
}

int	check_zero(int b, char **argv)
{
	if (ft_strcmp(argv[2], "/") == 0 && b == 0)
	{
		write(1, "Stop : division by zero\n", 24);
		return (0);
	}
	if (ft_strcmp(argv[2], "%") == 0 && b == 0)
	{
		write(1, "Stop : modulo by zero\n", 22);
		return (0);
	}
	return (1);
}

int	parse(int a, int b, char **argv, int *res)
{
	if (!check_zero(b, argv))
		return (-1);
	if (ft_strcmp(argv[2], "+") == 0)
		*res = plus(a, b);
	else if (ft_strcmp(argv[2], "-") == 0)
		*res = minus(a, b);
	else if (ft_strcmp(argv[2], "*") == 0)
		*res = multiply(a, b);
	else if (ft_strcmp(argv[2], "/") == 0)
		*res = divide(a, b);
	else if (ft_strcmp(argv[2], "%") == 0)
		*res = modulo(a, b);
	else
		*res = 0;
	return (1);
}

int	main(int argc, char **argv)
{
	int	res;
	int	a;
	int	b;

	if (argc != 4)
		return (-1);
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	if (parse(a, b, argv, &res) == -1)
		return (-1);
	ft_putnbr(res);
	write(1, "\n", 1);
	return (0);
}
