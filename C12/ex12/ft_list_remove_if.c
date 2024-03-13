/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 22:55:50 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/03/13 23:49:42 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
void (*free_fct)(void *))
{
	t_list	*current;
	t_list	*next;
	t_list	*prev;

	current = *begin_list;
	prev = *begin_list;
	while (current)
	{
		next = current->next;
		if (cmp(current->data, data_ref) == 0)
		{
			if (current == *begin_list)
			{
				*begin_list = next;
				prev = next;
			}
			else
				prev->next = current->next;
			free_fct(current->data);
			free(current);
		}
		else
			prev = current;
		current = next;
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

void	delete(void *data)
{
	printf("deleting data %s\n", (char *)data);
}

int	ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	return (s1[i] - s2[i]);
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
	ft_list_remove_if(&list, "42", &ft_strcmp, &delete);
	ft_print_list(list);
	return (0);
}
*/