/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 00:50:57 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/02/05 00:57:52 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
//#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < n)
		i++;
	return (s1[i] - s2[i]);
}

/*
int	main(void)
{
	char	string1[] = "apple";
	char	string2[] = "banana";
	char	string3[] = "apples";
	char	string4[] = "programming";
	char	string5[] = "programmers";
	char	string6[] = "apple";

	printf("%s vs %s : %d\n", string1, string2, strncmp(string1, string2, 6));
	printf("%s vs %s : %d\n", string1, string2, ft_strncmp(string1, string2, 6));
	printf("%s vs %s : %d\n", string1, string3, strncmp(string1, string3, 6));
	printf("%s vs %s : %d\n", string1, string3, ft_strncmp(string1, string3, 6));
	printf("%s vs %s : %d\n", string1, string6, strncmp(string1, string6, 6));
	printf("%s vs %s : %d\n", string1, string6, ft_strncmp(string1, string6, 6));
	printf("%s vs %s : %d\n", string1, string4, strncmp(string1, string4, 7));
	printf("%s vs %s : %d\n", string1, string4, ft_strncmp(string1, string4, 7));
	printf("%s vs %s : %d\n", string4, string5, strncmp(string4, string5, 7));
	printf("%s vs %s : %d\n", string4, string5, ft_strncmp(string4, string5, 7));
	return (0);
}
*/
