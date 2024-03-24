/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 02:17:40 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/03/24 21:42:43 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_strbcat(char *old, char *new_content, size_t max, size_t copy)
{
	char		*res;
	size_t		res_idx;
	size_t		copy_idx;

	res_idx = 0;
	if ((ft_strlen(old) + copy <= max))
		res = (char *)malloc((ft_strlen(old) + copy + 1) * sizeof(char));
	else
		res = (char *)malloc((max + 1) * sizeof(char));
	if (!res)
		return (NULL);
	copy_idx = (ft_strlen(old) + copy > max) * (ft_strlen(old) - (max - copy));
	while (old[copy_idx])
		res[res_idx++] = old[copy_idx++];
	copy_idx = (copy >= max) * (copy - max);
	while (copy_idx < copy)
		res[res_idx++] = new_content[copy_idx++];
	res[res_idx] = 0;
	free(old);
	return (res);
}

void	print_header(char *file_name)
{
	static int	newline = 0;

	if (newline)
		ft_putchar_fd('\n', STDOUT);
	ft_putstr_fd("==> ", STDOUT);
	ft_putstr_fd(file_name, STDOUT);
	ft_putstr_fd(" <==\n", STDOUT);
	newline++;
}

t_option	get_opt(int argc, char **argv, int *error)
{
	t_option	opt;
	char		*read;
	int			idx;

	opt.input = 1;
	read = NULL;
	if (argc > 1 && !ft_strcmp(argv[opt.input], "-c") && opt.input + 1 < argc)
		read = argv[++opt.input];
	else if (argc > 1 && !ft_strncmp(argv[opt.input], "-c", 2))
		read = &argv[opt.input][2];
	idx = 0;
	opt.size = 0;
	opt.valid = 1;
	while (read && read[idx] >= '0' && read[idx] <= '9')
		opt.size = opt.size * 10 + (size_t)(read[idx++] - '0');
	if (opt.size && read && read[idx] && get_sid(&read[idx]) != -1)
		opt.size = mult_suffix(opt.size, &read[idx]);
	opt.input++;
	opt.valid *= (idx != 0) * !(read && read[idx] && get_sid(&read[idx]) == -1);
	if (!opt.valid)
	{
		put_opt_err(argc, argv);
		(*error)++;
	}
	return (opt);
}

void	put_opt_err(int argc, char **argv)
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
