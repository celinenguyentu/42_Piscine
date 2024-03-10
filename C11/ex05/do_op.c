/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:19:47 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/03/10 19:39:05 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_find(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	puterr(char *op, char *b)
{
	if (ft_strlen(op) != 1 || ft_find(op[0], "+-/*%") == -1)
	{
		ft_putstr("0");
		return (0);
	}
	if (op[0] == '/' && ft_atoi(b) == 0)
	{
		ft_putstr("Stop : division by zero");
		return (0);
	}
	if (op[0] == '%' && ft_atoi(b) == 0)
	{
		ft_putstr("Stop : modulo by zero");
		return (0);
	}
	return (1);
}

int	do_op(char *a, char op, char *b)
{
	int	(*operators[5])(int, int);

	operators[0] = &add;
	operators[1] = &sub;
	operators[2] = &mul;
	operators[3] = &div;
	operators[4] = &mod;
	if (op == '+')
		return (operators[0](ft_atoi(a), ft_atoi(b)));
	else if (op == '-')
		return (operators[1](ft_atoi(a), ft_atoi(b)));
	else if (op == '*')
		return (operators[2](ft_atoi(a), ft_atoi(b)));
	else if (op == '/')
		return (operators[3](ft_atoi(a), ft_atoi(b)));
	else if (op == '%')
		return (operators[4](ft_atoi(a), ft_atoi(b)));
	else
		return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		if (puterr(argv[2], argv[3]))
			ft_putnbr(do_op(argv[1], argv[2][0], argv[3]));
		ft_putchar('\n');
	}
	return (0);
}
