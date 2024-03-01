/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 03:31:12 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/02/03 03:48:12 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

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

/*
int	main(void)
{
	char	str1[] = "HELLO WORLD!";
	char	str2[] = "hello world!";
	char	str3[] = "Hello World";
	char	str4[] = "hell0 w0rld";

	printf("%s upcased is %s\n", str1, ft_strupcase(str1));
	printf("%s upcased is %s\n", str2, ft_strupcase(str2));
	printf("%s upcased is %s\n", str3, ft_strupcase(str3));
	printf("%s upcased is %s\n", str4, ft_strupcase(str4));
	printf("new str4 is %s\n", str4);
	return (0);
}
*/
