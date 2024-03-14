/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 02:59:22 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/03/14 04:20:43 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#define BUFF_SIZE 100

int	ft_display_file(char *file_name)
{
	int		fd;
	char	buffer[BUFF_SIZE];
	int		bytes_read;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (0);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, sizeof(buffer));
		if (bytes_read == -1)
			return (0);
		write(1, buffer, bytes_read);
	}
	if (close(fd) == -1)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		write(2, "File name missing.\n", 19);
		return (1);
	}
	else if (argc > 2)
	{
		write(2, "Too many arguments.\n", 20);
		return (1);
	}
	else if (!ft_display_file(argv[1]))
	{
		write(2, "Cannot read file.\n", 18);
		return (1);
	}
	return (0);
}
