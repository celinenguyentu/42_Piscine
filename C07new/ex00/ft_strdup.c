/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 03:44:57 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/02/20 11:34:55 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*copy;

	i = 0;
	while (src[i] != '\0')
		i++;
	copy = malloc((i + 1) * sizeof(char));
	if (copy)
	{
		i = 0;
		while (src[i] != '\0')
		{
			copy[i] = src[i];
			i++;
		}
		copy[i] = '\0';
		return (copy);
	}
	else
		return (NULL);
}

/*	//TEST CASES
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	*str1 = "Coucou les cocos !";
	char	*str2;
	char	*str3;

	str2 = ft_strdup(str1);
	str3 = strdup(str1);
	printf("%s\n", str1);
	printf("%s\n", str2);
	printf("%s\n", str3);
	free(str2);
	free(str3);
	return (0);
}
*/
