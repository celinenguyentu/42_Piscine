/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 05:28:41 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/03/11 03:07:08 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)(void *, void *))
{
	t_list	*current;
	t_list	*output;
	t_list	*tmp;

	current = *begin_list;
	output = 0;
	while (current && cmp)
	{
		*begin_list = (*begin_list)->next;
		if (!output || cmp(output->data, current->data) > 0)
		{
			current->next = output;
			output = current;
		}
		else
		{
			tmp = output;
			while (tmp->next && cmp(tmp->next->data, current->data) < 0)
				tmp = tmp->next;
			current->next = tmp->next;
			tmp->next = current;
		}
		current = *begin_list;
	}
	*begin_list = output;
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

int	main(void)
{
	t_list	*list;

	list = NULL;
	ft_list_push_front(&list, "42");
	ft_list_push_front(&list, "Hello");
	ft_list_push_front(&list, "world");
	ft_list_push_front(&list, "Salut");
	ft_print_list(list);
	ft_list_sort(&list, &ft_strcmp);
	ft_print_list(list);
	return (0);
}
*/