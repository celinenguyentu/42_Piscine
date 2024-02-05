/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 23:15:37 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/02/03 01:58:50 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

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

/*
int	main(void)
{
	char	str1[] = "Hello World!";
	char	str2[15];
	char	*str3;

	str3 = ft_strcpy(str2, str1);
	printf("%s\n", str1);
	printf("%s\n", str2);
	printf("%s\n", str3);
	return (0);
}
*/
