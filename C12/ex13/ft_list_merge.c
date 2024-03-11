/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 00:00:37 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/03/11 01:09:15 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list, t_list *begin_list2)
{
	t_list	*current;

	current = *begin_list;
	if (current)
	{
		while (current->next)
			current = current->next;
		current->next = begin_list2;
	}
	else
		*begin_list = begin_list2;
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

int	main(void)
{
	t_list	*list1;
	t_list	*list2;

	list1 = NULL;
	list2 = NULL;
	ft_list_push_front(&list1, "42");
	ft_list_push_front(&list1, "World");
	ft_list_push_front(&list2, "Hello");
	ft_list_push_front(&list2, "salutsalut");
	ft_print_list(list1);
	ft_print_list(list2);
	ft_list_merge(&list1, list2);
	ft_print_list(list1);
	return (0);
}
*/