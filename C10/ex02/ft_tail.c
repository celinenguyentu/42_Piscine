/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 04:56:52 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/03/24 21:46:30 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_puterror(char *program_name, char *file_name, int *error)
{
	ft_putstr_fd(basename(program_name), STDERR);
	ft_putstr_fd(": ", STDERR);
	if (!ft_strncmp(strerror(errno), "Cannot allocate memory", 23))
		ft_putstr_fd("malloc", STDERR);
	else
		ft_putstr_fd(file_name, STDERR);
	ft_putstr_fd(": ", STDERR);
	ft_putstr_fd(strerror(errno), STDERR);
	ft_putstr_fd("\n", STDERR);
	(*error)++;
}

int	check_memory(size_t size)
{
	char	*buffer;

	buffer = (char *)malloc(size);
	if (!buffer)
		return (0);
	else
	{
		free(buffer);
		return (1);
	}
}

int	display_fd(int fd, size_t size)
{
	char	buffer[BUFF_SIZE];
	ssize_t	bytes_read;
	char	*content;

	if (fd == STDIN && !check_memory(size))
		return (0);
	content = (char *)malloc(sizeof(char));
	if (!content)
		return (0);
	content[0] = 0;
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, sizeof(buffer));
		if (bytes_read == -1)
			return (0);
		content = ft_strbcat(content, buffer, size, (size_t)bytes_read);
		if (!content)
			return (0);
	}
	ft_putstr_fd(content, STDOUT);
	free(content);
	if (fd != 0 && close(fd) == -1)
		return (0);
	return (1);
}

int	display_file(char *file_name, size_t size, int header)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (0);
	else
	{
		if (header)
			print_header(file_name);
		if (!display_fd(fd, size))
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int			error;
	int			header;
	t_option	opt;

	error = 0;
	header = 0;
	opt = get_opt(argc, argv, &error);
	if (opt.valid)
	{
		if (opt.input == argc)
		{
			if (!display_fd(STDIN, opt.size))
				ft_puterror(argv[0], argv[opt.input], &error);
		}
		else if (!strcmp(argv[opt.input], "--") && ++opt.input == argc
			&& !display_fd(STDIN, opt.size))
			ft_puterror(argv[0], argv[opt.input - 1], &error);
		header = (opt.input + 1 < argc);
		while (opt.input < argc)
		{
			if (!display_file(argv[opt.input++], opt.size, header))
				ft_puterror(argv[0], argv[opt.input - 1], &error);
		}
	}
	return (EXIT_SUCCESS * (error == 0) + EXIT_FAILURE * (error > 0));
}
