/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:43:37 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/02/02 18:20:02 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_num(const char num[], const int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		write(1, &num[i], 1);
		i++;
	}	
	write(1, ", ", 2);
}

// size = 5
// 01234 first + index
// 56789 last
// 01234
// i = 4

void	ft_print_combn_rec(char * num, int size, int i)
{
	if (i == size - 1) 
		ft_print_num(num, size);
		
	else
		num[i+1] = num[i] + 1;
		ft_print_combn_rec(num, size, i++);
		





void	ft_print_combn(int n)
{
	char	number[n];
	int	i;

	number[0] = '0';
	i = 0;
	ft_print_combn_rec(number, i);
}


/*
	while ((number[i] <= '9' - n + 1 + i) && (i < n) && (i >= 0)) 
	// tant que le ieme chiffre ne dépasse pas son max et qu'on reste dans le tableau
	{
		if (i < n - 1)
		{
			i++;
			number[i] = number[i-1] + 1;
		}
		if (i == n - 1)
		{
			ft_print_num(number, n);
			i--;
		}
	
	}
*/	
	
	//number[0] = '0';
	//for (int i=1; i<n; i++) number[i] = number[i-1] + 1;
	//ft_print_num(number, n);
}

int	main(void)
{
	//ft_print_combn(1);
	ft_print_combn(2);
	//ft_print_combn(5);
	return (0);
}

//n = 3 max = 789
//012 013 014 015 ... 019 
//023 024 ... 029 
//034 ... 039 
//...
//078 079
//089 
//123 124 ... 129 
//134 ... 139
//178 179
//189
//234 ... 239
//...
//289
//...
//678 679
//689
//789






//n = 4 - 0123 0124 0125 ... 0129 0134 ... 6789
