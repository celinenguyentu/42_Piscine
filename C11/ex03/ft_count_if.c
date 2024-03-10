/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 04:31:26 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/03/10 19:35:32 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (i < length)
	{
		if (f(tab[i]))
			count++;
		i++;
	}
	return (count);
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
	int	res = ft_count_if(strs, 5, &starts_upcase);

	printf("List has %d strings that starts upcase\n", res);
	return (0);
}
*/