/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:42:23 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/02/19 10:47:22 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			break ;
		else
			i++;
	}
	if (str[i] == c)
		return (i);
	else
		return (-1);
}

int	ft_is_base(char *base)
{
	int	i;
	int	is_base;

	i = 0;
	is_base = 1;
	while (base[i] != '\0')
	{
		if (base[i] < 33 || base[i] > 126)
			is_base = 0;
		if (base[i] == '+' || base[i] == '-')
			is_base = 0;
		if (ft_find(base[i], &base[i + 1]) != -1)
			is_base = 0;
		i++;
	}
	if (i <= 1)
		is_base = 0;
	return (is_base);
}

int	ft_base_to_decimal(char *str, int start, int size, char *base)
{
	int	res;
	int	i;
	int	fact;
	int	j;

	i = 0;
	res = 0;
	while (i < size)
	{
		fact = 1;
		j = 0;
		if (size - i - 1 != 0)
		{
			j = 0;
			while (j++ < size - i - 1)
				fact *= ft_find('\0', base);
		}
		res += ft_find(str[start + i], base) * fact;
		i++;
	}
	return (res);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	i;
	int	number;
	int	num_size;

	i = 0;
	sign = 1;
	number = 0;
	while (str[i] != '\0' && ft_find(str[i], " \f\n\r\t\v") >= 0)
		i++;
	while (str[i] != '\0' && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	num_size = i;
	while (str[num_size] != '\0' && ft_find(str[num_size], base) >= 0)
		num_size++;
	number = ft_base_to_decimal(str, i, num_size - i, base);
	return (sign * number);
}
