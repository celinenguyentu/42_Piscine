/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:33:46 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/03/10 19:37:13 by cnguyen-         ###   ########.fr       */
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

void	ft_sort_string_tab(char **tab)
{
	int		i;
	char	*tmp;
	int		j;

	i = 1;
	while (tab[i])
	{
		tmp = tab[i];
		j = i;
		while (j > 0 && ft_strcmp(tab[j - 1], tmp) > 0)
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

int	main(void)
{
	char	*strs[] = {"hello", "Leonel", "Celine", "42", "examshell", NULL};
	int	i = 0;

	ft_sort_string_tab(strs);
	while(strs[i])
	{
		printf("%s\n", strs[i]);
		i++;
	}
	return (0);
}
*/