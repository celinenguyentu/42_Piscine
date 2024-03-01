/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 05:18:10 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/02/03 20:02:22 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (!(size == 0))
	{
		while (src[i] != '\0' && i < size -1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
		while (src[i] != '\0')
			i++;
	}
	return (i);
}

/*
int	main(void)
{
	char		src[] = "Hello 42, ici cnguyen- !"; // 24
	char		dest1[10];
	char		dest2[30];
	unsigned int	n1;
	unsigned int	n2;

	n1 = ft_strlcpy(dest1, src, 10);
	n2 = ft_strlcpy(dest2, src, 30);
	printf("source is %d long\n", n1);
	printf("dest1 : %s\n", dest1);
	printf("dest2 : %s\n", dest2);
	return (0);
}
*/
