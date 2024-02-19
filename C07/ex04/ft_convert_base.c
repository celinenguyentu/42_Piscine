/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 06:37:30 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/02/19 10:47:56 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_find(char c, char *str);
int	ft_is_base(char *base);
int	ft_atoi_base(char *str, char *base);

char	*ft_push_front(char *str, char c)
{
	int		size;
	char	*res;
	int		i;

	size = ft_find('\0', str) + 2;
	res = malloc(size * sizeof(char));
	res[0] = c;
	i = 1;
	while (i < ft_find('\0', str) + 1)
	{
		res[i] = str[i - 1];
		i++;
	}
	res[i] = '\0';
	free(str);
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	num;
	int		sign;
	int		base_len;
	char	*res;

	if (!ft_is_base(base_from) || !ft_is_base(base_to))
		return (NULL);
	num = ft_atoi_base(nbr, base_from);
	if (num < 0)
	{
		sign = -1;
		num = -num;
	}
	base_len = ft_find('\0', base_to);
	res = malloc(sizeof(char));
	res[0] = '\0';
	while (num > 0)
	{
		res = ft_push_front(res, base_to[num % base_len]);
		num /= base_len;
	}
	if (sign == -1)
		res = ft_push_front(res, '-');
	return (res);
}

/*	//TEST CASES
#include <stdio.h>

int	main(void)
{
	char	*str = ft_convert_base(" --24162fk", "01234", "0123456789abcdef");
	char	*min = ft_convert_base("  -2147483648", "0123", "0123456789abc");	
	printf("%s\n", str);
	printf("%s\n", min);

	return (0);
}
*/
