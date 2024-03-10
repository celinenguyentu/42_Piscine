/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 04:14:24 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/03/10 19:31:35 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char*))
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (f(tab[i]))
			return (1);
		i++;
	}
	return (0);
}

/*	//TEST CASES
#include <stdio.h>

int	starts_upcase(char *str)
{
	return (str[0] >= 'A' && str[0] <= 'Z');
}

int	main(void)
{
	char	*strs[] = {"hello", "Leonel", "Celine", "42", "examshell", NULL};
	int	res = ft_any(strs, &starts_upcase);

	printf("List has a string that starts upcase : %d\n", res);
	return (0);
}
*/