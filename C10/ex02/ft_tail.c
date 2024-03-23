/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 04:56:52 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/03/23 01:03:26 by cnguyen-         ###   ########.fr       */
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

void	ft_print_header(char *file_name)
{
	static int	newline = 0;

	if (newline)
		ft_putchar_fd('\n', STDOUT);
	ft_putstr_fd("==> ", STDOUT);
	ft_putstr_fd(file_name, STDOUT);
	ft_putstr_fd(" <==\n", STDOUT);
	newline++;
}

void	ft_opterr(int argc, char **argv)
{
	ft_putstr_fd(basename(argv[0]), STDERR);
	if (argc > 1 && !ft_strncmp(argv[1], "-c", 2) && (argv[1][2] || argc > 2))
	{
		ft_putstr_fd(": illegal offset -- ", STDERR);
		if (argv[1][2])
			ft_putstr_fd(&argv[1][2], STDERR);
		else
			ft_putstr_fd(argv[2], STDERR);
		ft_putstr_fd(": Invalid argument\n", STDERR);
	}
	else
	{
		if (argc == 1 || argv[1][0] != '-' || !ft_strncmp(argv[1], "-", 2))
			ft_putstr_fd(": command requires option -- c", STDERR);
		else if (argc == 2 && !ft_strncmp(argv[1], "-c", 3))
			ft_putstr_fd(": option requires an argument -- c", STDERR);
		else
		{
			ft_putstr_fd(": invalid option -- ", STDERR);
			ft_putchar_fd(argv[1][1], STDERR);
		}
		ft_putstr_fd("\nusage: ", STDERR);
		ft_putstr_fd(basename(argv[0]), STDERR);
		ft_putstr_fd(" -c # [file ...]\n", STDERR);
	}
}

int	ft_display_fd(int fd, int size)
{
	char	buffer[BUFF_SIZE];
	int		bytes_read;
	char	*content;

	content = malloc(sizeof(char));
	if (!content)
		return (0);
	content[0] = 0;
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, sizeof(buffer));
		if (bytes_read == -1)
			return (0);
		content = ft_strbcat(content, buffer, size, bytes_read);
		if (!content)
			return (0);
	}
	write(STDOUT, content, size);
	free(content);
	if (fd != 0 && close(fd) == -1)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	int	input;
	int	fd;
	int	error;
	int	size;
	int	header;

	input = 1;
	error = 0;
	size = -1;
	header = 0;
	if (argc > 1 && !ft_strncmp(argv[input], "-c", 3) && input + 1 < argc)
		size = ft_atoi_suffix(argv[++input]);
	else if (argc > 1 && argv[input][0] == '-' && argv[input][1] == 'c')
		size = ft_atoi_suffix(&argv[input][2]);
	input++;
	if (size == -1)
	{
		ft_opterr(argc, argv);
		error++;
	}
	else
	{
		if (input == argc)
			ft_display_fd(STDIN, size);
		else if (!strncmp(argv[input], "--", 3))
		{
			if (input + 1 == argc)
				ft_display_fd(STDIN, size);
			input++;
		}
		header = (input + 1 < argc);
		while (input < argc)
		{
			fd = open(argv[input], O_RDONLY);
			if (fd == -1)
				ft_puterror(argv[0], argv[input], &error);
			else
			{
				if (header)
					ft_print_header(argv[input]);
				if (!ft_display_fd(fd, size))
					ft_puterror(argv[0], argv[input], &error);
			}
			input++;
		}
	}
	if (error)
		return (EXIT_FAILURE);
	else
		return (EXIT_SUCCESS);
}
/*
int main(void)
{
	size_t size;
	int s;
	
	s = ft_atoi_suffix("42G");
	size = -1;
	//if (size == -1)
		printf("yoo %ld\n", size);
		printf("yoo %d\n", s);
	return (0);
}*/

/*
malloc max = 9223372036854775807
- NUM may have a multiplier suffix: b 512, kB 1000, K 1024, MB 1000*1000, 
M 1024*1024, GB 1000*1000*1000, G 1024*1024*1024, and so on for 
T, P, E, Z, Y, R, Q. Binary prefixes can be used, too: KiB=K, MiB=M, and so on.
*/