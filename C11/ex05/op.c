/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:07:21 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/02/29 18:42:20 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	add(int a, int b)
{
	return (a + b);
}

int	sub(int a, int b)
{
	return (a - b);
}

int	div(int a, int b)
{
	if (b == 0)
		return (0);
	else
		return (a / b);
}

int	mul(int a, int b)
{
	return (a * b);
}

int	mod(int a, int b)
{
	if (b == 0)
		return (0);
	else
		return (a % b);
}
