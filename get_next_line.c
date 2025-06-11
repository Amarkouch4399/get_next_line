/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouamarko <ouamarko@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:56:48 by ouamarko          #+#    #+#             */
/*   Updated: 2025/06/11 16:43:56 by ouamarko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_extract_line(char *line)
{
	int	i;
	char	*final_line;

	i = 0;
	while (line[i] != '\n')
	{
		i++;
	}
	final_line = malloc(i);
	i = 0;
	while (line[i] != '\n')
	{
		final_line[i] = line[i];
		i++;
	}
	return (final_line);
}

char	*ft_fill_line(int fd, char *line)
{
	ssize_t	count;
	char	buffer[buffer_size + 1];
	char	*stock = NULL;
	
	while ((count = read(fd, buffer, buffer_size)) > 0)
	{
		buffer[count + 1] = '\0';
		if (!stock)
			stock = ft_strdup(buffer);
		else
			line = ft_strjoin(stock, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (ft_extract_line(line));
}

char	*ft_get_next_line(int fd)
{
	char	*line;

	line = NULL;
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
	line = NULL;
	while ((line = ft_get_next_line(fd)) != NULL)
    	{
        	printf("%s", line);
    	}
	close(fd);
	return (0);
}
