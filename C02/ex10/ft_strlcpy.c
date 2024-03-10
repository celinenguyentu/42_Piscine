/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 22:16:40 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/03/10 15:18:11 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	}
	while (src[i] != '\0')
		i++;
	return (i);
}

/*	//TEST CASES
#include <stdio.h>
#include <string.h>
//#include <bsd/string.h> // on Linux compile with flag -lbsd

void	test(unsigned int size)
{
	char			src[] = "Hello world !";
	char			dest_og[20];
	char			dest_mine[20];
	int				n_og;
	unsigned int	n_mine;

	n_og = strlcpy(dest_og, src, size);
	n_mine = ft_strlcpy(dest_mine, src, size);
	printf("Source : '%s'\n", src);
	printf("Copying %d characters\n", size);
	printf("strlcpy : '%s', return length %d\n", dest_og, n_og);
	printf("ft_strlcpy : '%s', return length %d\n\n", dest_mine, n_mine);
}

int	main(void)
{
	test(20);
	test(18);
	test(10);
	test(1);
	test(0);
	return (0);
}
*/