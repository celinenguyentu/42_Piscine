/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 22:40:36 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/03/23 00:55:59 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <errno.h>
# include <libgen.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0
# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define BUFF_SIZE 8000

# include <stdio.h>

typedef struct s_option
{
	size_t	size;
	int		valid;
	int		input;
	
} t_option;

// libft.c
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
int		ft_strlen(char *str);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
char	*ft_strbcat(char *old, char *new_content, int max, int copy);
// ft_atoi_suffix.c
int		map_get_index(char **keys, char *to_find);
int		map_get(char **keys, char *to_find, int *values);
int		ft_atoi_suffix(char *str);

#endif