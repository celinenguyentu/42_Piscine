/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:27:45 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/03/13 03:29:38 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*elem;
	t_list	*current;

	elem = ft_create_elem(data);
	current = *begin_list;
	if (elem)
	{
		if (*begin_list)
		{
			while (current->next)
				current = current->next;
			current->next = elem;
		}
		else
			*begin_list = elem;
	}
}

/*	//TEST CASES
#include <stdio.h>

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
	t_list	*list;

	list = NULL;
	ft_list_push_back(&list, "Hello");
	ft_list_push_back(&list, " ");
	ft_list_push_back(&list, "!");
	ft_print_list(list);
	return (0);
}
*/