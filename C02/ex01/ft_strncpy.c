/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:50:30 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/02/13 12:10:58 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/*	//TEST CASES
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char str1[] = "Hello Planet 42 !"; // len(str1) = 17
	char str2[17];
	char str3[17];
	strncpy(str2, str1, 17);
	printf("Copying in same length string with strncpy : %s\n", str2);
	ft_strncpy(str3, str1, 17);
	printf("Copying in same length string with ft_strncpy : %s\n", str3);
	char str4[10];
	char str5[10];
	strncpy(str4, str1, 10);
	printf("Copying in smaller string with strncpy : %s\n", str4);
	ft_strncpy(str5, str1, 10);
	printf("Copying in smaller string with ft_strncpy : %s\n", str5);
	char str6[30];
	char str7[30];
	strncpy(str6, str1, 30);
	printf("Copying in bigger  string with strncpy : %s\n", str6);	
	ft_strncpy(str7, str1, 30);
	printf("Copying in bigger string with ft_strncpy : %s\n", str7);
	return (0);
}
*/
