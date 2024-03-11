/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 01:41:24 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/03/11 03:45:57 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
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

/*	//TEST CASES
#include <stdio.h>

int	main(void)
{
	t_btree *node1;
	t_btree	*node2;

	node1 = btree_create_node("hello");
	node2 = btree_create_node("42");
	printf("Node 1 (%p)\nleft : %p\nright : %p\nitem : %s\n", node1,
	node1->left, node1->right, (char *)node1->item);
	printf("Node 2 (%p)\nleft : %p\nright : %p\nitem : %s\n", node2,
	node2->left, node2->right, (char *)node2->item);
	return (0);
}
*/