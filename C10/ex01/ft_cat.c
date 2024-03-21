/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 04:29:34 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/03/21 04:42:35 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>
#include <fcntl.h>

#define BUFF_SIZE 8000

void	ft_putstr_fd(char *str, int fd)
{
	while (*str)
		write(fd, str++, 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_puterror(char *program_name, char *file_name)
{
	ft_putstr_fd(basename(program_name), 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(file_name, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
}

int	ft_display_fd(int fd)
{
	char	buffer[BUFF_SIZE];
	int		bytes_read;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, sizeof(buffer));
		if (bytes_read == -1)
			return (0);
		write(1, buffer, bytes_read);
	}
	if (fd != 0 && close(fd) == -1)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	int	input;
	int fd;
	int error;
	
	input = 1;
	error = 0;
	if (argc == 1)
		ft_display_fd(0);
	while (input < argc)
	{
		if (!strcmp(argv[input], "-"))
			ft_display_fd(0);
		else if (!strcmp(argv[input], "--") && input == 1)
		{
			if (argc == 2)
				ft_display_fd(0);
		}
		else
		{
			fd = open(argv[input], O_RDONLY);
			if (fd == -1 || !ft_display_fd(fd))
			{
				ft_puterror(argv[0], argv[input]);
				error++;
			}
		}
		input++;
	}
	if (error)
		return(1);
	else
		return(0);
}
