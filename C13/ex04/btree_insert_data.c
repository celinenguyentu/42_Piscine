/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 02:47:51 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/03/11 04:15:00 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *,
void *))
{
	t_btree	*current;
	t_btree	*node;

	current = *root;
	node = btree_create_node(item);
	if (!current && item)
		*root = node;
	else if (node && item && cmpf)
	{
		while (current)
		{
			if (cmpf(current->item, node->item) > 0 && current->left)
				current = current->left;
			else if (cmpf(current->item, node->item) <= 0 && current->right)
				current = current->right;
			else
				break ;
		}
		if (cmpf(current->item, node->item) > 0)
			current->left = node;
		else if (cmpf(current->item, node->item) <= 0)
			current->right = node;
	}
}

/*	//TEST CASES
#include <stdio.h>
#include <stdlib.h>

t_btree	*btree_create_node(void *item)
{
	t_btree	*node;

	node = malloc(sizeof(t_btree));
	if (!node)
		return (NULL);
	node->left = NULL;
	node->right = NULL;
	node->item = item;
	return (node);
}

void	btree_print_infix(t_btree *root)
{
	if (root)
	{
		btree_print_infix(root->left);
		printf("%s ", (char *)root->item);
		if (root->left)
			printf("[%s]", (char *)root->left->item);
		else
			printf("[na]");
		if (root->right)
			printf("[%s] ", (char *)root->right->item);
		else
			printf("[na] ");
		btree_print_infix(root->right);
	}
}

int	ft_strcmp(void *s1, void *s2)
{
	int		i;
	char	*str1;
	char	*str2;

	i = 0;
	str1 = (char *)s1;
	str2 = (char *)s2;
	while (str1[i] == str2[i] && str1[i])
		i++;
	return (str1[i] - str2[i]);
}

int	main(void)
{
	t_btree	*root;

	root = NULL;
	btree_insert_data(&root, "7", &ft_strcmp);
	btree_insert_data(&root, "9", &ft_strcmp);
	btree_insert_data(&root, "3", &ft_strcmp);
	btree_insert_data(&root, "5", &ft_strcmp);
	btree_insert_data(&root, "4", &ft_strcmp);
	btree_insert_data(&root, "1", &ft_strcmp);
	btree_insert_data(&root, "8", &ft_strcmp);
	btree_insert_data(&root, "2", &ft_strcmp);
	btree_insert_data(&root, "6", &ft_strcmp);
	btree_insert_data(&root, "7", &ft_strcmp);
	btree_print_infix(root);
	printf("\n");
}
*/