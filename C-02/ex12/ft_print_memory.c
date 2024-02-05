/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 20:04:07 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/02/04 23:59:14 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	print_address_hex(char *add)
{
	int			i;
	unsigned long int	a;
	char			*hexadecimal;
	char			hex_address[16];

	i = 0;
	a = (unsigned long int)add;
	hexadecimal = "0123456789abcdef";
	while (i < 16)
	{
		hex_address[16 - 1 - i] = hexadecimal[a % 16];
		a /= 16;
		i++;
	}
	i = 0;
	while (i < 16)
	{
		write(1, &hex_address[i], 1);
		i++;
	}
}

void	print_char_hex(char *addr, int left)
{
	char	*hexadecimal;
	int	j;

	hexadecimal = "0123456789abcdef";
	j = 0;
	while (j < 16 && j < left)
	{
		write(1, &hexadecimal[addr[j] / 16], 1);
		write(1, &hexadecimal[addr[j] % 16], 1);
		if (j % 2 == 1)
			write(1, " ", 1);
		j++;
		if (addr[j - 1] == '\0')
			break ;
	}
	while (j < 16)
	{
		write(1, "  ", 2);
		if (j % 2 == 1)
			write(1, " ", 1);
		j++;
	}
}

void	print_char(char *addr, int left)
{
	int	j;

	j = 0;
	while (j < 16 && j < left)
	{
		if (addr[j] >= 32 && addr[j] <= 126)
			write(1, &addr[j], 1);
		else
			write(1, ".", 1);
		j++;
		if (addr[j - 1] == '\0')
			break ;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (size != 0)
	{
		while (i < size)
		{
			print_address_hex(&addr[i]);
			write(1, ": ", 2);
			print_char_hex(&addr[i], size - i);
			print_char(&addr[i], size - i);
			write(1, "\n", 1);
			i += 16;
		}
	}
	return (addr);
}
/*
int	main(void)
{
	char	*addr;

	addr = "Hello 42 ! \n Ici cnguyen-. \n\a On test print_memory \t mais le code ASCII etendue fonctionne pas, c'est la merde -_- ...";
	ft_print_memory(addr, 119);
	return (0);
}
*/
