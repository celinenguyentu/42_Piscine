/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:32:30 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/02/29 17:58:33 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

/*	//TEST CASES
#include <stdio.h>

int	main(void)
{
	int	i;
	char	*str = "Hello World !";

	i = ft_strlen(str);
	printf("Length of '%s' is %d\n", str, i);
	return (0);
}
*/
