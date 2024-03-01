/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 22:00:37 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/02/08 22:52:57 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	i;
	int	is_numeric;

	i = 0;
	is_numeric = 1;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 48 && str[i] <= 57))
		{
			is_numeric = 0;
			break ;
		}
		i++;
	}
	return (is_numeric);
}

/*	//TEST CASES
#include <stdio.h>

int	main(void)
{
	char	str1[] = "18 42 18 42";
	char	str2[] = "893203841";
	char	str3[] = "249294!";
	char	str4[] = "string92";
	char	str5[] = "cnguyen-";
	char	str6[] = "";

	printf("\"%s\" is numeric : %d\n", str1, ft_str_is_numeric(str1));
	printf("\"%s\" is numeric : %d\n", str2, ft_str_is_numeric(str2));
	printf("\"%s\" is numeric : %d\n", str3, ft_str_is_numeric(str3));
	printf("\"%s\" is numeric : %d\n", str4, ft_str_is_numeric(str4));
	printf("\"%s\" is numeric : %d\n", str5, ft_str_is_numeric(str5));
	printf("\"%s\" is numeric : %d\n", str6, ft_str_is_numeric(str6));
	return (0);
}
*/
