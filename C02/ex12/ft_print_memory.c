/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 22:19:04 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/03/14 02:35:30 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_address_hex(unsigned char *add)
{
	int					i;
	char				*hexadecimal;
	char				hex_address[17];
	unsigned long int	ul_add;

	i = 0;
	ul_add = (unsigned long int)add;
	hexadecimal = "0123456789abcdef";
	hex_address[16] = '\0';
	while (i < 16)
	{
		hex_address[16 - 1 - i] = hexadecimal[ul_add % 16];
		ul_add /= 16;
		i++;
	}
	write(1, hex_address, 16);
	write(1, ": ", 2);
}

void	print_char_hex(unsigned char *add, int left)
{
	char	*hexadecimal;
	int		j;

	hexadecimal = "0123456789abcdef";
	j = 0;
	while (j < 16 && j < left)
	{
		write(1, &hexadecimal[add[j] / 16], 1);
		write(1, &hexadecimal[add[j] % 16], 1);
		if (j % 2 == 1)
			write(1, " ", 1);
		j++;
	}
	while (j < 16)
	{
		write(1, "  ", 2);
		if (j % 2 == 1)
			write(1, " ", 1);
		j++;
	}
}

void	print_char(char *add, int left)
{
	int	i;

	i = 0;
	while (i < 16 && i < left)
	{
		if (add[i] >= 32 && add[i] <= 126)
			write(1, &add[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned char	*add;

	i = 0;
	add = (unsigned char *)addr;
	while (i < size)
	{
		print_address_hex(&add[i]);
		print_char_hex(&add[i], size - i);
		print_char((char *)&add[i], size - i);
		write(1, "\n", 1);
		i += 16;
	}
	return (addr);
}

/*	//TEST CASES
#include <stdio.h>

int	main(void)
{
	char	*addr;

	addr = "Bonjour les aminches\t\n\tc\a est fou\ttout\tce qu on peut faire avec\t\n\tprint_memory\n\n\n\tlol.lol\n "; //buffsize92
	ft_print_memory(addr, 92);
	return (0);
}
*/