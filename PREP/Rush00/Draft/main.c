/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 09:40:41 by gbriand           #+#    #+#             */
/*   Updated: 2024/02/11 11:42:04 by gbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int x, int y)
{
	int	compteur_y;
	int	compteur_x;

	if (x <= 0 || y <= 0)
	{
		compteur_y = 1;
		compteur_x = 1;
		if (compteur_y == 1)
		{
			write(1, "A", 1);
			compteur_x++;
			while (compteur_x < x)
			{
				if (x > 2)
				{
					write(1, "B", 1);
				}
				compteur_x++;
			}
			if (x > 1)
			{
				write(1, "C", 1);
			}
			write(1, "\n", 1);
			compteur_y++;
			compteur_x = 1;
		}
		while (compteur_y < y)
		{
			write(1, "B", 1);
			compteur_x++;
			while (compteur_x < x)
			{
				write(1, " ", 1);
				compteur_x++;
			}
			compteur_y++;
			compteur_x = 1;
			if (x > 1)
			{
				write(1, "B", 1);
			}
			write(1, "\n", 1);
		}
		if (compteur_y == y && y > 1)
		{
			write(1, "C", 1);
			compteur_x++;
			while (compteur_x < x)
			{
				if (x > 2)
				{
					write(1, "B", 1);
				}
				compteur_x++;
			}
			if (x > 1)
			{
				write(1, "A", 1);
			}
		}
		if (y > 1)
		{
			write(1, "\n", 1);
		}
		compteur_y++;
		compteur_x = 1;
	}
}

int	main(void)
{
	rush(1, 40);
	return (0);
}
