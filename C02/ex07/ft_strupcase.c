/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 22:11:27 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/02/09 22:26:14 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 97 && str[i] <= 122)
			str[i] -= 32;
		i++;
	}
	return (str);
}

/*	//TEST CASES
#include <stdio.h>

int	main(void)
{
	char	str1[] = "HELLO WORLD!";
	char	str2[] = "hello world!";
	char	str3[] = "Hello World";
	char	str4[] = "hell0 w0rld";

	printf("\"%s\" upcased is ", str1);
	printf("\"%s\"\n", ft_strupcase(str1));
	printf("\"%s\" upcased is ", str2);
	printf("\"%s\"\n", ft_strupcase(str2));
	printf("\"%s\" upcased is ", str3);
	printf("\"%s\"\n", ft_strupcase(str3));
	printf("\"%s\" upcased is ", str4);
	printf("\"%s\"\n", ft_strupcase(str4));
}
*/
