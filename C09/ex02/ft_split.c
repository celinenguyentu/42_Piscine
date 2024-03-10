/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:50:10 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/03/10 18:27:09 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char c, char *charset)
{
	int	i;
	int	is_sep;

	is_sep = 0;
	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
		{
			is_sep = 1;
			break ;
		}
		i++;
	}
	return (is_sep);
}

int	count_strings(char *str, char *charset)
{
	int	i;
	int	count;
	int	inside;

	i = 0;
	count = 0;
	inside = 0;
	while (str[i])
	{
		if (is_sep(str[i], charset) && inside)
			inside = 0;
		if (!is_sep(str[i], charset) && !inside)
		{
			count++;
			inside = 1;
		}
		i++;
	}
	return (count);
}

int	append_item(int item, char *str, char *charset, char **res)
{
	int	i;
	int	size;

	size = 0;
	while (str[size] && !is_sep(str[size], charset))
		size++;
	res[item] = malloc((size + 1) * sizeof(char));
	i = 0;
	while (str[i] && !is_sep(str[i], charset))
	{
		res[item][i] = str[i];
		i++;
	}
	res[item][i] = '\0';
	return (i);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	char	**res;
	int		item;

	res = malloc((count_strings(str, charset) + 1) * sizeof(char *));
	i = 0;
	item = 0;
	while (str[i])
	{
		if (is_sep(str[i], charset))
			i++;
		else
		{
			i += append_item(item, &str[i], charset, res);
			item++;
		}
	}
	res[item] = 0;
	return (res);
}

/*	//TEST CASES
#include <stdio.h>

int	main(void)
{
	char	*string1 = "Hello world, les sis et les bros";
	char	*sep1 = "lou";
	printf("%d ", count_strings(string1, sep1));
	char	**res1 = ft_split(string1, sep1);
	int		i = 0;
	while (res1[i] != 0)
	{
		printf("'%s' ", res1[i]);
		i++;
	}
	printf("\n");
	char	*string2 = "Jpp Le Mec De Mon Rush";
	char	*sep2 = "LeJCLeS";
	printf("%d ", count_strings(string2, sep2));
	char	**res2 = ft_split(string2, sep2);
	i = 0;
	while (res2[i] != 0)
	{
		printf("'%s' ", res2[i]);
		i++;
	}
	printf("\n");
	free(res1);
	free(res2);
	return (0);
}
*/