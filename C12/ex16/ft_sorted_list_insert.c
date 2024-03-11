/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 20:30:25 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/03/11 03:18:34 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_sorted_list_insert(t_list **begin_list, void *data,
int (*cmp)(void *, void *))
{
	t_list	*elem;
	t_list	*current;

	elem = ft_create_elem(data);
	current = *begin_list;
	if (elem && data && cmp)
	{
		if (!current || cmp(current->data, data) > 0)
		{
			elem->next = current;
			*begin_list = elem;
		}
		else
		{
			while (current->next && cmp(current->next->data, data) < 0)
				current = current->next;
			elem->next = current->next;
			current->next = elem;
		}
	}
	else
		free(elem);
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
	t_list	*list;

	list = NULL;
	ft_list_push_front(&list, "E");
	ft_list_push_front(&list, "D");
	ft_list_push_front(&list, "C");
	ft_list_push_front(&list, "B");
	ft_list_push_front(&list, "A");
	ft_print_list(list);
	ft_sorted_list_insert(&list, "42", &ft_strcmp);
	ft_print_list(list);
	return (0);
}
*/