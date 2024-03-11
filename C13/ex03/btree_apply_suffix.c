/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_suffix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 02:08:30 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/03/11 03:46:39 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
	if (root && applyf)
	{
		btree_apply_suffix(root->left, applyf);
		btree_apply_suffix(root->right, applyf);
		applyf(root->item);
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

void	print_node(void *item)
{
	printf("%s ", (char *)item);
}

int	main(void)
{
	t_btree	*r, *a, *b, *c, *d, *e, *f, *h, *i, *j, *k, *l;

	r = btree_create_node("r");
	a = btree_create_node("a");
	b = btree_create_node("b");
	c = btree_create_node("c");
	d = btree_create_node("d");
	e = btree_create_node("e");
	f = btree_create_node("f");
	h = btree_create_node("h");
	i = btree_create_node("i");
	j = btree_create_node("j");
	k = btree_create_node("k");
	l = btree_create_node("l");
	r->left = a;
	r->right = b;
	a->left = c;
	a->right = d;
	c->right = h;
	d->left = i;
	d->right = j;
	j->left = l;
	b->left = e;
	b->right = f;
	e->left = k;
	btree_apply_suffix(r, &print_node);
	return (0);
}
*/