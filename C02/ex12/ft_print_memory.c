/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 22:19:04 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/02/15 10:05:04 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_address_hex(char *add)
{
	int					i;
	char				*hexadecimal;
	char				hex_address[16];
	unsigned long int	ul_add;

	i = 0;
	ul_add = (unsigned long int)add;
	hexadecimal = "0123456789abcdef";
	while (i < 16)
	{
		hex_address[16 - 1 - i] = hexadecimal[ul_add % 16];
		ul_add /= 16;
		i++;
	}
	i = 0;
	while (i < 16)
	{
		write(1, &hex_address[i], 1);
		i++;
	}
}

void	print_char_hex(char *add, int left)
{
	char	*hexadecimal;
	int		j;

	hexadecimal = "0123456789abcdef";
	j = 0;
	while (j < 16 && j < left)
	{
		write(1, &hexadecimal[(unsigned char)add[j] / 16], 1);
		write(1, &hexadecimal[(unsigned char)add[j] % 16], 1);
		if (j % 2 == 1)
			write(1, " ", 1);
		j++;
		if (add[j - 1] == '\0')
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

int	print_char(char *add, int left)
{
	int	i;
	int	end_flag;

	i = 0;
	end_flag = 0;
	while (i < 16 && i < left)
	{
		if (add[i] >= 32 && add[i] <= 126)
			write(1, &add[i], 1);
		else
			write(1, ".", 1);
		i++;
		if (add[i - 1] == '\0')
		{
			end_flag = 1;
			break ;
		}
	}
	return (end_flag);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	char			*add;
	int				end_flag;

	i = 0;
	add = (char *)addr;
	end_flag = 0;
	if (size != 0)
	{
		while (i < size && !end_flag)
		{
			print_address_hex(&add[i]);
			write(1, ": ", 2);
			print_char_hex(&add[i], size - i);
			end_flag = print_char(&add[i], size - i);
			write(1, "\n", 1);
			i += 16;
		}
	}
	return (addr);
}

/*	//TEST CASES
#include <stdio.h>

int	main(void)
{
	char	*addr1;
	char	*addr2;
	char	addr3[] = {47, 48, 126, 127, 128, 129, 130}; 

	addr1 = "Hello 42 !\n\n\aOn test print_memory\tmais la // replace for tests
		norminette casse les co*** ..."; //buffsize73
	ft_print_memory(addr1, 73);

	addr2 = "Bonjour les aminches\t\n\tc\a est fou\ttout\tce qu on //replace
		peut faire avec\t\n\tprint_memory\n\n\n\tlol.lol\n "; //buffsize92
	ft_print_memory(addr2, 92);
	ft_print_memory(addr3, 255);
	return (0);
}
*/
