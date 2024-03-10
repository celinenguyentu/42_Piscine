/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 22:08:34 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/03/10 05:43:30 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;
	int	is_printable;

	i = 0;
	is_printable = 1;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 32 && str[i] <= 126))
		{
			is_printable = 0;
			break ;
		}
		i++;
	}
	return (is_printable);
}

/*	//TEST CASES
#include <stdio.h>

int	main(void)
{
	char	str1[] = "Hello World !";
	char	str2[] = "HELLO\n";
	char	str3[] = "HELLO!\t";
	char	str4[] = "Hello42";
	char	str5[] = "";

	printf("\"%s\" is printable : %d\n", str1, ft_str_is_printable(str1));
	printf("\"%s\" is printable : %d\n", str2, ft_str_is_printable(str2));
	printf("\"%s\" is printable : %d\n", str3, ft_str_is_printable(str3));
	printf("\"%s\" is printable : %d\n", str4, ft_str_is_printable(str4));
	printf("\"%s\" is printable : %d\n", str5, ft_str_is_printable(str5));
	return (0);
}
*/