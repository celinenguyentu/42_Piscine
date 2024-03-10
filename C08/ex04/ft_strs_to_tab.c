/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:01:28 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/03/10 19:11:40 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*result;

	result = malloc((ac + 1) * sizeof(t_stock_str));
	if (!result)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		result[i].size = ft_strlen(av[i]);
		result[i].str = av[i];
		result[i].copy = malloc((ft_strlen(av[i]) + 1) * sizeof(char));
		if (!result[i].copy)
			return (NULL);
		else
			result[i].copy = ft_strcpy(result[i].copy, av[i]);
		i++;
	}
	result[i].size = 0;
	result[i].str = 0;
	result[i].copy = 0;
	return (result);
}

/*	//TEST CASES
#include <stdio.h>

void	modify_str_tab(struct s_stock_str *tab, unsigned int i, char *str)
{
	tab[i].copy = str;
}

int	main(void)
{
	char	*string[] = {"Hello", "World", "les sis", "et", "les bros"};
	struct s_stock_str	*tab;

	tab = ft_strs_to_tab(5, string);
	ft_show_tab(tab);
	modify_str_tab(tab, 1, "42");
	ft_show_tab(tab);
	return (0);
}
*/