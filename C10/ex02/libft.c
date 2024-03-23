/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 23:25:19 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/03/23 00:06:27 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *str, int fd)
{
	while (*str)
		ft_putchar_fd(*str++, fd);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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

char	*ft_strbcat(char *old, char *new_content, int max, int copy)
{
	char	*res;
	int		res_idx;
	int		copy_idx;

	res_idx = 0;
	if (ft_strlen(old) + copy <= max)
		res = malloc((ft_strlen(old) + copy + 1) * sizeof(char));
	else
		res = malloc((max + 1) * sizeof(char));
	if (!res)
		return (NULL);
	copy_idx = (ft_strlen(old) + copy > max) * (ft_strlen(old) - (max - copy));
	while (old[copy_idx])
		res[res_idx++] = old[copy_idx++];
	copy_idx = (copy >= max) * (copy - max);
	while (copy_idx < copy)
		res[res_idx++] = new_content[copy_idx++];
	res[res_idx] = 0;
	free(old);
	return (res);
}
