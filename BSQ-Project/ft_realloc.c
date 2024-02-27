/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfischof <pfischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:18:53 by pfischof          #+#    #+#             */
/*   Updated: 2024/02/27 23:56:30 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

char	*ft_realloc(char *buffer, int size)
{
	int		i;
	char	*new_buffer;

	i = 0;
	while (buffer[i] != '\0')
		i++;
	new_buffer = malloc((i + size + 1) * sizeof(char));
	if(!new_buffer)
		return (NULL);
	i = 0;
	while (buffer[i])
	{
		new_buffer[i] = buffer[i];
		i++;
	}
	free(buffer);
	return (new_buffer);
}
