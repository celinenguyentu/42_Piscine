/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 22:14:43 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/02/13 12:28:57 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_lowercase(char c)
{
	return (c >= 97 && c <= 122);
}

int	is_uppercase(char c)
{
	return (c >= 65 && c <= 90);
}

int	is_alphanumeric(char c)
{
	return ((c >= 48 && c <= 57) || is_uppercase(c) || is_lowercase(c));
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (is_alphanumeric(str[i]))
		{
			if (is_lowercase(str[i]))
				str[i] -= 32;
			i++;
			while (is_alphanumeric(str[i]))
			{
				if (is_uppercase(str[i]))
					str[i] += 32;
				i++;
			}
		}
		else
			i++;
	}
	return (str);
}

/*	//TEST CASES
#include <stdio.h>

char	*ft_strcapitalize(char *str);

int	main(void)
{
	char	str[] = "SalUt, coMmenT tu vas ? //replace for tests
	       	42motS quarAnte-deux; cinquantE+et+un";

	printf("\"%s\" capitalized becomes \n", str);
	printf("\"%s\"\n", ft_strcapitalize(str));
	return (0);
}
*/
