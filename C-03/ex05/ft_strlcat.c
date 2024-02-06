/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 02:17:11 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/02/05 02:43:19 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
//#include <stdio.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < size)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (i + j);
}

/*
int	main(void)
{
	char	string[100] = "Hello ";
	char	add1[100] = "World, ";
	char	add2[100] = "";
	char	add3[100] = "les soeurs, les frères, les fratés ";
	char	add4[100] = "le sang de la veine !";

	printf("%d : %s\n", ft_strlcat(string, add1, 10), string);
	printf("%d : %s\n", ft_strlcat(string, add2, 10), string);
	printf("%d : %s\n", ft_strlcat(string, add3, 25), string);
	printf("%d : %s\n", ft_strlcat(string, add4, 7), string);
	return (0);
}
*/
