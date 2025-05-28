/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouamarko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:06:42 by ouamarko          #+#    #+#             */
/*   Updated: 2025/05/28 15:42:11 by ouamarko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_next_line(int fd)
{
	char	*line;
	char	c;
	static ssize_t count;
	int	i;

	i = 0;
	line = malloc(buffer_size);
	if (!line)
		return (NULL);
	while((count = read(fd, &c, 1) > 0))
	{
		line[i] = c;
		if (line[i] == '\n')
			break ;
		i++;
	}
	 if (count <= 0 && i == 0)
	 {
		 free(line);
		 return (NULL);
	 }
	line[i] = '\0';
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
