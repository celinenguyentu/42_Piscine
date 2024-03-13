/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 05:08:36 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/03/13 03:32:45 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->next = NULL;
	elem->data = data;
	return (elem);
}

/*	//TEST CASES
#include <stdio.h>

int	main(void)
{
	int		data1 = 42;
	char	*data2 = "Hello";
	t_list	*elem1 = ft_create_elem(&data1);
	t_list	*elem2 = ft_create_elem(data2);

	printf("First element : %d\n", *(int *)elem1->data);
	printf("Second element : %s\n", (char *)elem2->data);
	data1 = 18;
	printf("First element modified : %d\n", *(int *)elem1->data);
	return (0);
}
*/