/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:32:30 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/03/10 04:52:06 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	char	*str = "Hello World !";

	printf("Length of '%s' is %d\n", str, ft_strlen(str));
	return (0);
}
*/