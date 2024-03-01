/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 00:59:12 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/02/05 01:39:44 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
//#include <stdio.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}
/*
int	main(void)
{
	char	string1[100] = "Hello ";
	char	string2[100] = "World";
	char	string3[100] = ", ";
	char	string4[100] = "whassup";
	char	string5[100] = " ?";

	printf("%s\n", ft_strcat(string1, string2));
	printf("%s\n", ft_strcat(string1, string3));
	printf("%s\n", ft_strcat(string1, string4));
	printf("%s\n", ft_strcat(string1, string5));
	return (0);
}
*/
