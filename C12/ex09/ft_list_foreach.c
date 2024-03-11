/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 21:58:42 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/03/10 22:26:25 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach(t_list	*begin_list, void (*f)(void *))
{
	while (begin_list && f)
	{
		f(begin_list->data);
		begin_list = begin_list->next;
	}
}

/*	//TEST CASES
#include <stdio.h>
#include <stdlib.h>

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

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*elem;

	elem = ft_create_elem(data);
	if (elem)
	{
		if (*begin_list)
			elem->next = *begin_list;
		*begin_list = elem;
	}
}

void	ft_print_list(t_list *list)
{
	if (!list)
	{
		printf("NULL\n");
		return ;
	}
	printf("%s -> ", (char *)list->data);
	ft_print_list(list->next);
}

void	ft_print_elem(void	*data)
{
	printf("%s -> ", (char *)data);
}

int	main(void)
{
	t_list	*list;

	list = NULL;
	ft_list_push_front(&list, "42");
	ft_list_push_front(&list, "World");
	ft_list_push_front(&list, "Hello");
	ft_list_push_front(&list, "salutsalut");
	ft_print_list(list);
	ft_list_foreach(list, &ft_print_elem);
	return (0);
}
*/