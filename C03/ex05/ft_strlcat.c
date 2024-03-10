/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 22:30:20 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/03/10 16:22:46 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0' && i < size)
		i++;
	if (i < size)
	{
		while (src[j] != '\0' && i + j < size - 1)
		{
			dest[i + j] = src[j];
			j++;
		}
		dest[i + j] = '\0';
	}
	while (src[j] != '\0')
		j++;
	return (i + j);
}

/*	//TEST CASES
#include <string.h>
#include <stdio.h>
//#include <bsd/string.h> // on Linux, compile with flag -lbsd

void	test(unsigned int dsize)
{
	char	string1[100] = "Hello "; //len6
	char	string2[100] = "Hello ";
	char	add[100] = "World of 42!"; //len12
	int	n_og;
	int	n_me;

	n_og = strlcat(string1, add, dsize);
	printf("strlcat concatenated : '%s'\n", string1);
	printf("Value returned = %d\n", n_og);
	n_me = ft_strlcat(string2, add, dsize);
	printf("ft_strlcat concatenated : '%s'\n", string2);
	printf("Value returned = %d\n\n", n_me);
}

int	main(void)
{
	test(0);
	test(4);
	test(6);
	test(10);
	test(19);
	test(25);
 	return (0);
}
*/