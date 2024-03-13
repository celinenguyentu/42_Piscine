/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 21:55:52 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/03/13 03:22:03 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
int (*cmp)())
{
	t_list	*current;
	t_list	*insert;

	current = *begin_list1;
	while (begin_list2)
	{
		insert = begin_list2;
		begin_list2 = begin_list2->next;
		if (!current || cmp(current->data, insert->data) > 0)
		{
			insert->next = current;
			*begin_list1 = insert;
			current = insert;
		}
		else
		{
			while (current->next && cmp(current->next->data, insert->data) < 0)
				current = current->next;
			insert->next = current->next;
			current->next = insert;
		}
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

int	ft_strcmp(void *str1, void *str2)
{
	int		i;
	char	*s1;
	char	*s2;

	i = 0;
	s1 = (char *)str1;
	s2 = (char *)str2;
	while (s1[i] == s2[i] && s1[i])
		i++;
	return (s1[i] - s2[i]);
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
	ft_list_push_front(&list1, "E");
	ft_list_push_front(&list1, "D");
	ft_list_push_front(&list1, "C");
	ft_list_push_front(&list1, "B");
	ft_list_push_front(&list1, "A");
	ft_list_push_front(&list2, "hello");
	ft_list_push_front(&list2, "Erwan");
	ft_list_push_front(&list2, "Celine");
	ft_list_push_front(&list2, "Adrien");
	ft_list_push_front(&list2, "42");
	ft_print_list(list1);
	ft_print_list(list2);
	ft_sorted_list_merge(&list1, list2, &ft_strcmp);
	ft_print_list(list1);
	return (0);
}
*/