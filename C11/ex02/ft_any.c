/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 04:14:24 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/02/29 15:05:16 by cnguyen-         ###   ########.fr       */
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

int	is_name(char *str)
{
	return (str[0] >= 'A' && str[0] <= 'Z');
}

int	main(void)
{
	char	*strs[] = {"coucou", "Leonel", "celine", "42", "examshell", NULL};
	int	res = ft_any(strs, &is_name);

	printf("List has a name : %d\n", res);
	return (0);
}
*/
