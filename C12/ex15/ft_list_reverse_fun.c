/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:41:29 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/03/13 23:53:32 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	if (!begin_list)
		return (0);
	else
		return (1 + ft_list_size(begin_list->next));
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*swap;
	int		size;
	int		i;
	int		j;
	void	*tmp;

	size = ft_list_size(begin_list);
	i = 0;
	while (i++ < size / 2)
	{
		swap = begin_list;
		j = 0;
		while (j++ < size - 2 * (i - 1) - 1)
			swap = swap->next;
		tmp = swap->data;
		swap->data = begin_list->data;
		begin_list->data = tmp;
		begin_list = begin_list->next;
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
	t_list	*list;

	list = NULL;
	ft_list_push_front(&list, "A");
	ft_list_push_front(&list, "B");
	ft_list_push_front(&list, "C");
	ft_list_push_front(&list, "D");
	ft_list_push_front(&list, "E");
	ft_list_push_front(&list, "F");
	ft_print_list(list);
	ft_list_reverse_fun(list);
	ft_print_list(list);
	return (0);
}
*/