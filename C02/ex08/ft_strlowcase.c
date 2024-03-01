/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 22:13:27 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/02/09 22:33:18 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] += 32;
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

	printf("\"%s\"", str1);
	printf(" lowcased is \"%s\"\n", ft_strlowcase(str1));
	printf("\"%s\"", str2);
	printf(" lowcased is \"%s\"\n", ft_strlowcase(str2));
	printf("\"%s\"", str3);
	printf(" lowcased is \"%s\"\n", ft_strlowcase(str3));
	printf("\"%s\"", str4);
	printf(" lowcased is \"%s\"\n", ft_strlowcase(str4));
	return (0);
}
*/
