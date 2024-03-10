/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 22:26:25 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/03/10 15:55:07 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/*	//TEST CASES
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	string1[100] = "Hello ";
	char	string2[100] = "Hello ";
	char	string3[100] = "World, ";
	char	string4[100] = "whassup";
	char	string5[100] = " ?";
	char	string6[100] = "";

	printf("'%s' concat with ft_strcat\n", ft_strcat(string1, string3));
	printf("'%s' concat with strcat\n", strcat(string2, string3));
	printf("'%s' concat with ft_strcat\n", ft_strcat(string1, string4));
	printf("'%s' concat with strcat\n", strcat(string2, string4));
	printf("'%s' concat with ft_strcat\n", ft_strcat(string1, string5));
	printf("'%s' concat with strcat\n", strcat(string2, string5));
	printf("'%s' concat with ft_strcat\n", ft_strcat(string1, string6));
	printf("'%s' concat with strcat\n", strcat(string2, string6));
	return (0);
}
*/