/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 22:04:29 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/03/10 05:39:40 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	i;
	int	is_lowercase;

	i = 0;
	is_lowercase = 1;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 97 && str[i] <= 122))
		{
			is_lowercase = 0;
			break ;
		}
		i++;
	}
	return (is_lowercase);
}

/*	//TEST CASES
#include <stdio.h>

int	main(void)
{
	char	str1[] = "Hello world !";
	char	str2[] = "hello";
	char	str3[] = "hello!";
	char	str4[] = "hello42";
	char	str5[] = "";

	printf("\"%s\" is lowercase : %d\n", str1, ft_str_is_lowercase(str1));
	printf("\"%s\" is lowercase : %d\n", str2, ft_str_is_lowercase(str2));
	printf("\"%s\" is lowercase : %d\n", str3, ft_str_is_lowercase(str3));
	printf("\"%s\" is lowercase : %d\n", str4, ft_str_is_lowercase(str4));
	printf("\"%s\" is lowercase : %d\n", str5, ft_str_is_lowercase(str5));
	return (0);
}
*/