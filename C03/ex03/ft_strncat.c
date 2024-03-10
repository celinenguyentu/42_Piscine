/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 22:26:40 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/03/10 16:01:12 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < nb)
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
	char	string3[100] = "World ";
	char	string4[100] = " whassup";
	char	string5[100] = " ?????";
	char	string6[100] = "";

	printf("'%s' concat with strncat\n", strncat(string1, string3, 0));
	printf("'%s' concat with ft_strncat\n", ft_strncat(string2, string3, 0));
	printf("'%s' concat with strncat\n", strncat(string1, string4, 10));
	printf("'%s' concat with ft_strncat\n", ft_strncat(string2, string4, 10));
	printf("'%s' concat with strncat\n", strncat(string1, string5, 2));
	printf("'%s' concat with ft_strncat\n", ft_strncat(string2, string5, 2));
	printf("'%s' concat with strncat\n", strncat(string1, string6, 2));
	printf("'%s' concat with ft_strncat\n", ft_strncat(string2, string6, 2));
	return (0);
}
*/