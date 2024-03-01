/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 22:25:58 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/02/14 18:27:04 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	else
	{
		while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
			i++;
		if (i < n)
			return (s1[i] - s2[i]);
		else
			return (0);
	}
}

/*	//TEST CASES
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	string1[] = "apple";
	char	string2[] = "banana";
	char	string3[] = "apples";
	char	string4[] = "programming";
	char	string5[] = "programmers";
	char	string6[] = "apple";

	printf("%s vs %s : %d\n", string1, string2, strncmp(string1, string2, -2));
	printf("%s vs %s : %d\n", string1, string2, ft_strncmp(string1, string2, -2));
	printf("%s vs %s : %d\n", string1, string3, strncmp(string1, string3, 6));
	printf("%s vs %s : %d\n", string1, string3, ft_strncmp(string1, string3, 6));
	printf("%s vs %s : %d\n", string1, string6, strncmp(string1, string6, 6));
	printf("%s vs %s : %d\n", string1, string6, ft_strncmp(string1, string6, 6));
	printf("%s vs %s : %d\n", string1, string4, strncmp(string1, string4, 7));
	printf("%s vs %s : %d\n", string1, string4, ft_strncmp(string1, string4, 7));
	printf("%s vs %s : %d\n", string4, string5, strncmp(string4, string5, 9));
	printf("%s vs %s : %d\n", string4, string5, ft_strncmp(string4, string5, 9));
	return (0);
}
*/
