/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 20:38:28 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/03/10 16:32:42 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

/*	//TEST CASES
int	main(void)
{
	char	*str1 = "Hello\n";
	char	*str2 = "World\n";

	ft_putstr(str1);
	ft_putstr(str2);
	return (0);
}
*/