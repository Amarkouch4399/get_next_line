/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouamarko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:06:42 by ouamarko          #+#    #+#             */
/*   Updated: 2025/05/28 20:16:48 by ouamarko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_fill_line_buffer(int fd, char *left_c, char *line)
{
	int	i;
	ssize_t	count;
	char	temp[buffer_size];
	char	c;

	i = 0;
	while((count = read(fd, temp, buffer_size)) > 0)
	{
		if (temp[i] == '\n')
			while (i < buffer_size)
			{
				temp[i] = line[i];
				i++;
			}
			break ;
		i++;
	}
	return (left_c);
}

char	*ft_get_next_line(int fd)
{
	char	*line;
	ssize_t count;

	line = malloc(buffer_size);
	if (!line)
		return (NULL);
	ft_fill_line_buffer(fd, NULL, line);	
	if (count <= 0)
	 {
		 free(line);
		 return (NULL);
	 }
	return (line);
}

int	main()
{
	int	fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return(-1);
	while ((line = ft_get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		printf("\n");
		free(line);
	}
	close(fd);
	return (0);
}
