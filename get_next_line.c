/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouamarko <ouamarko@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:56:48 by ouamarko          #+#    #+#             */
/*   Updated: 2025/06/08 15:25:55 by ouamarko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



char	*ft_fill_line(int fd, char *line)
{
	ssize_t	count;
	char	buffer[buffer_size + 1];
	int	i;
	int	j;
	static char	*stock;
	
	i = 0;
	line = malloc(buffer_size + 1);
	if (!line)
		return (NULL);
	while ((count = read(fd, buffer, buffer_size)) > 0)
	{
		buffer[count] = '\0';
		j = 0;
		while(buffer[j] != '\n' && j < count)
		{
			line[i] = buffer[j];
			i++;
			j++;
		}
		line[i] = '\0';
		stock = malloc(count);
		while (i < count)
		{
			stock[i] = buffer[i];
			i++;	
			j++;
		}
	}
	return (line);
}

char	*ft_get_next_line(int fd)
{
	char	*line;
	ssize_t count;
	char	buffer[buffer_size + 1];	

	line = ft_fill_line(fd, line);
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
    	}
	close(fd);
	return (0);
}
