/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 03:03:15 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/02/03 03:09:59 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

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

/*
int	main(void)
{
	char	str1[] = "Hello les cocos du 13";
	char	str2[] = "hello";
	char	str3[] = "hello!";
	char	str4[] = "string92";
	char	str5[] = "c nguyen";
	char	str6[] = "";

	printf("%s is lowercase : %d\n", str1, ft_str_is_lowercase(str1));
	printf("%s is lowercase : %d\n", str2, ft_str_is_lowercase(str2));
	printf("%s is lowercase : %d\n", str3, ft_str_is_lowercase(str3));
	printf("%s is lowercase : %d\n", str4, ft_str_is_lowercase(str4));
	printf("%s is lowercase : %d\n", str5, ft_str_is_lowercase(str5));
	printf("%s is lowercase : %d\n", str6, ft_str_is_lowercase(str6));
	return (0);
}
*/
