/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 03:51:26 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/02/03 04:00:56 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

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

/*
int	main(void)
{
	char	str1[] = "HELLO WORLD!";
	char	str2[] = "hello world!";
	char	str3[] = "Hello World";
	char	str4[] = "hell0 w0rld";

	printf("%s ", str1);
	printf("lowcased is %s\n", ft_strlowcase(str1));
	printf("%s ", str2);
	printf("lowcased is %s\n", ft_strlowcase(str2));
	printf("%s ", str3);
	printf("lowcased is %s\n", ft_strlowcase(str3));
	printf("%s ", str4);
	printf("lowcased is %s\n", ft_strlowcase(str4));
	printf("new str3 is %s\n", str3);
	return (0);
}
*/
