/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:52:50 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/03/10 19:38:26 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	char	*tmp;
	int		j;

	i = 1;
	while (tab[i])
	{
		tmp = tab[i];
		j = i;
		while (j > 0 && cmp(tab[j - 1], tmp) > 0)
		{
			tab[j] = tab[j - 1];
			j--;
		}
		tab[j] = tmp;
		i++;
	}
}

/*	//TEST CASES
#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int	main(void)
{
	char	*strs[] = {"hello", "Leonel", "Celine", "42", "examshell", NULL};
	int	i = 0;

	ft_advanced_sort_string_tab(strs, &ft_strcmp);
	while(strs[i])
	{
		printf("%s\n", strs[i]);
		i++;
	}
	return (0);
}
*/