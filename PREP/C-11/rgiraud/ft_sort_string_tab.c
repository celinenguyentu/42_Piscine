/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:36:04 by rgiraud           #+#    #+#             */
/*   Updated: 2023/08/22 18:08:02 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
}

void	ft_swap(char **pt1, char **pt2)
{
	char	*temp;

	temp = *pt1;
	*pt1 = *pt2;
	*pt2 = temp;
}

int	ft_strlen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		i++;
	}
	return (i);
}

void	ft_sort_string_tab(char **tab)
{
	int	i;
	int	j;
	int	len;

	len = ft_strlen(tab);
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < (len - i - 1))
		{
			if (ft_strcmp(tab[j], tab[j + 1]) > 0)
			{
				ft_swap(&tab[j], &tab[j + 1]);
			}
			j++;
		}
		i++;
	}
}
