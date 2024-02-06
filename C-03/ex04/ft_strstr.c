/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 01:46:24 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/02/05 02:15:34 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
//#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == to_find[j] && to_find[j] != '\0')
			j++;
		if (to_find[j] == '\0')
			return (&str[i]);
		i++;
	}
	return (0);
}

/*
int	main(void)
{
	char	haystack[] = "Hello world, hello les frères, hello les soeurs";
	char	needle1[] = "";
	char	needle2[] = "les";
	char	needle3[] = "banane";
	char	needle4[] = ",";

	printf("%s\n", strstr(haystack, needle1));
	printf("%s\n", strstr(haystack, needle2));
	printf("%s\n", strstr(haystack, needle3));
	printf("%s\n", strstr(haystack, needle4));
	return (0);
}
*/
