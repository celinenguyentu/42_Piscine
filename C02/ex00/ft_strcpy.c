/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:39:40 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/02/13 12:09:26 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*	//TEST CASES
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str1[] = "Hello World!";
	char	str2[15];
	char	str3[15];
	
	printf("Original string : %s\n", str1);
	strcpy(str2, str1);
	printf("Copying with strcpy : %s\n", str2);
	ft_strcpy(str3, str1);
	printf("Copying with ft_strcpy : %s\n", str3);
	return (0);
}
*/
