/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 03:18:57 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/02/03 03:29:00 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	i;
	int	is_printable;

	i = 0;
	is_printable = 1;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 32))
		{
			is_printable = 0;
			break ;
		}
		i++;
	}
	return (is_printable);
}

/*
int	main(void)
{
	char	str1[] = "Hello les cocos du 13";
	char	str2[] = "HELLO";
	char	str3[] = "HELLO!";
	char	str4[] = "STRING92";
	char	str5[] = "C nguyen";
	char	str6[] = "";

	printf("%s is printable : %d\n", str1, ft_str_is_printable(str1));
	printf("%s is printable : %d\n", str2, ft_str_is_printable(str2));
	printf("%s is printable : %d\n", str3, ft_str_is_printable(str3));
	printf("%s is printable : %d\n", str4, ft_str_is_printable(str4));
	printf("%s is printable : %d\n", str5, ft_str_is_printable(str5));
	printf("%s is printable : %d\n", str6, ft_str_is_printable(str6));
	return (0);
}
*/
