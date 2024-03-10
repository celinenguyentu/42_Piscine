/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:59:21 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/03/10 05:34:35 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;
	int	is_alpha;

	i = 0;
	is_alpha = 1;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 65 && str[i] <= 90) && !(str[i] >= 97 && str[i] <= 122))
		{
			is_alpha = 0;
			break ;
		}
		i++;
	}
	return (is_alpha);
}

/*	//TEST CASES
#include <stdio.h>

int	main(void)
{
	char	str1[] = "Hello world";
	char	str2[] = "abcdefg";
	char	str3[] = "hello!";
	char	str4[] = "LeJCleS";
	char	str5[] = "";

	printf("\"%s\" is alpha : %d\n", str1, ft_str_is_alpha(str1));
	printf("\"%s\" is alpha : %d\n", str2, ft_str_is_alpha(str2));
	printf("\"%s\" is alpha : %d\n", str3, ft_str_is_alpha(str3));
	printf("\"%s\" is alpha : %d\n", str4, ft_str_is_alpha(str4));
	printf("\"%s\" is alpha : %d\n", str5, ft_str_is_alpha(str5));
	return (0);
}
*/