/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:27:22 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/03/14 00:10:37 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	btree_level_count(t_btree *root)
{
	if (root)
	{
		if (btree_level_count(root->left) >= btree_level_count(root->right))
			return (btree_level_count(root->left) + 1);
		if (btree_level_count(root->left) <= btree_level_count(root->right))
			return (btree_level_count(root->right) + 1);
	}
	return (0);
}

void	btree_apply(t_btree *root, int current_level, int level_apply,
void (*applyf)(void *item, int current_level, int is_first_elem))
{
	static int	is_first;

	if (current_level == 0)
		is_first = 1;
	if (root)
	{
		if (current_level == level_apply)
		{
			applyf(root->item, current_level, is_first);
			is_first = 0;
		}
		else if (current_level < level_apply)
		{
			btree_apply(root->left, current_level + 1, level_apply, applyf);
			btree_apply(root->right, current_level + 1, level_apply, applyf);
		}
	}
}

void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item,
int current_level, int is_first_elem))
{
	int	level;
	int	max_level;

	level = 0;
	max_level = btree_level_count(root);
	while (level < max_level)
		btree_apply(root, 0, level++, applyf);
}

/*	//TEST CASES
#include <stdio.h>

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

void	btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *,
void *))
{
	t_btree	*current;
	t_btree	*node;

	current = *root;
	node = btree_create_node(item);
	if (!current)
		*root = node;
	else if (node)
	{
		while (current)
		{
			if (cmpf(current->item, item) > 0 && current->left)
				current = current->left;
			else if (cmpf(current->item, item) <= 0 && current->right)
				current = current->right;
			else
				break ;
		}
		if (cmpf(current->item, item) > 0)
			current->left = node;
		else if (cmpf(current->item, item) <= 0)
			current->right = node;
	}
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

void	print_by_level(void *item, int current_level, int is_first_elem)
{
	if (is_first_elem)
		printf("\nLevel %d : ", current_level);
	printf("%s ", (char *)item);
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
	btree_insert_data(&root, "5", &ft_strcmp);
	btree_print_infix(root);
	btree_apply_by_level(root, &print_by_level);
}
*/