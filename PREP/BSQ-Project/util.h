/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:05:25 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/02/27 22:43:27 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_board
{
	int		rows;
	int		cols;
	char	markers[3];
	char	**map;
	int		**intmap;
}	t_board;

void	ft_putchar(char c);
char	*ft_realloc(char *buffer, int size);
int		**board_init(int rows, int cols);

int		valid_board(char *map);
void	print_board(t_board board, int view_intmap);
char	*read_file(char *file_name);
char	*read_stdin(void);
int		**create_intmap(char **map, int rows, int cols, char obs);

int	valid_board(char *board);
int	ft_is_printable(char c);
int	ft_is_digit(char c);

void	solver(char *board);

#endif
