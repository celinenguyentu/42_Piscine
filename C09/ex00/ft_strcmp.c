/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 22:25:26 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/02/13 12:38:37 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
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

	printf("%s vs %s : %d\n", string1, string2, strcmp(string1, string2));
	printf("%s vs %s : %d\n", string1, string2, ft_strcmp(string1, string2));
	printf("%s vs %s : %d\n", string1, string3, strcmp(string1, string3));
	printf("%s vs %s : %d\n", string1, string3, ft_strcmp(string1, string3));
	printf("%s vs %s : %d\n", string1, string6, strcmp(string1, string6));
	printf("%s vs %s : %d\n", string1, string6, ft_strcmp(string1, string6));
	printf("%s vs %s : %d\n", string1, string4, strcmp(string1, string4));
	printf("%s vs %s : %d\n", string1, string4, ft_strcmp(string1, string4));
	printf("%s vs %s : %d\n", string4, string5, strcmp(string4, string5));
	printf("%s vs %s : %d\n", string4, string5, ft_strcmp(string4, string5));
	return (0);
}
*/
