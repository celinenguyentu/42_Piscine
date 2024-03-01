/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 20:14:21 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/02/14 18:53:04 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

/*	//TEST CASES
#include <stdio.h>

int	main(void)
{
	char	str1[] = "Hello";
	char	str2[] = "World ";
	char	str3[] = "Les tests c'est chiant";

	printf("'%s' has %d characters\n", str1, ft_strlen(str1));
	printf("'%s' has %d characters\n", str2, ft_strlen(str2));
	printf("'%s' has %d characters\n", str3, ft_strlen(str3));
	return (0);
}
*/
