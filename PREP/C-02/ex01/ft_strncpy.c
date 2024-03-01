/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 23:42:08 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/02/03 02:00:43 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

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

/*
int	main(void)
{
	char str1[] = "Hello les loosers !";
	char str2[20];
	ft_strncpy(str2, str1, 20); // len(str1) = 20
	printf("%s\n", str2);
	char str3[10];
	ft_strncpy(str3, str1, 10); // len(str1) > 10
	printf("%s\n", str3);
	char str4[30];
	ft_strncpy(str4, str1, 30); // len(str1) < 30
	printf("%s\n", str4);
	return (0);
}
*/
