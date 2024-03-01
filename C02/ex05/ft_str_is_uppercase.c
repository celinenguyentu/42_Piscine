/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 22:07:15 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/02/09 21:52:15 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	i;
	int	is_uppercase;

	i = 0;
	is_uppercase = 1;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 65 && str[i] <= 90))
		{
			is_uppercase = 0;
			break ;
		}
		i++;
	}
	return (is_uppercase);
}

/*	//TEST CASES
#include <stdio.h>

int	main(void)
{
	char	str1[] = "Hello les cocos du 13";
	char	str2[] = "HELLO";
	char	str3[] = "HELLO!";
	char	str4[] = "STRING92";
	char	str5[] = "C nguyen";
	char	str6[] = "";

	printf("\"%s\" is uppercase : %d\n", str1, ft_str_is_uppercase(str1));
	printf("\"%s\" is uppercase : %d\n", str2, ft_str_is_uppercase(str2));
	printf("\"%s\" is uppercase : %d\n", str3, ft_str_is_uppercase(str3));
	printf("\"%s\" is uppercase : %d\n", str4, ft_str_is_uppercase(str4));
	printf("\"%s\" is uppercase : %d\n", str5, ft_str_is_uppercase(str5));
	printf("\"%s\" is uppercase : %d\n", str6, ft_str_is_uppercase(str6));
	return (0);
}
*/
