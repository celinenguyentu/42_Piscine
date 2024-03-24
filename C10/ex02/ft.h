/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 22:40:36 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/03/24 21:46:47 by cnguyen-         ###   ########.fr       */
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
# define BUFF_SIZE 80000

typedef struct s_option
{
	size_t	size;
	int		valid;
	int		input;
}	t_option;

// libft.c
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *str, int fd);
size_t		ft_strlen(char *str);
int			ft_strcmp(char *s1, char *s2);
int			ft_strncmp(char *s1, char *s2, unsigned int n);
// suffix.c
char		*ft_strupcase(char *str);
int			get_sid(char *to_find);
int			get_sval(char *to_find, int *values);
int			mult_overflow(size_t n1, size_t n2);
size_t		mult_suffix(size_t size, char *to_find);
// utils.c
char		*ft_strbcat(char *old, char *new_content, size_t max, size_t copy);
void		print_header(char *file_name);
t_option	get_opt(int argc, char **argv, int *error);
void		put_opt_err(int argc, char **argv);
// ft_tail.c
void		ft_puterror(char *program_name, char *file_name, int *error);
int			check_memory(size_t size);
int			display_fd(int fd, size_t size);
int			display_file(char *file_name, size_t size, int header);

#endif