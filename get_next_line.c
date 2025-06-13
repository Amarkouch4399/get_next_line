/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouamarko <ouamarko@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:56:48 by ouamarko          #+#    #+#             */
/*   Updated: 2025/06/13 13:01:34 by ouamarko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_extract_line(char *line)
{
	int		i;
	char	*final_line;

	i = 0;
	i = ft_strlen(line);
	final_line = malloc(i);
	i = 0;
	while (line[i] != '\n')
	{
		final_line[i] = line[i];
		i++;
	}
	return (final_line);
}

char	*ft_rest(char *line)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	j = 0;
	while (line[i] != '\n')
		i++;
	j = i;
	while (line[i] != '\0')
		i++;
	rest = malloc(i - j + 1);
	i = 0;
	while (line[j] != '\0')
	{
		rest[i] = line[j + 1];
		i++;
		j++;
	}
	rest[i] = '\0';
	return (rest);
}
/*
char	*ft_read_all_if_small(int fd)
{
	char	buffer[buffer_size];
	ssize_t	count;

	if (fd < 0 || buffer_size <= 0)
		return (NULL);

	buffer = malloc(buffer_size + 1);
	if (!buffer)
		return (NULL);

	count = read(fd, buffer, buffer_size);
	if (count <= 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[count] = '\0';
	return (buffer);
}
*/
char	*ft_fill_line(int fd, char *line, char *stock)
{
	ssize_t	count;
	char	buffer[buffer_size];
	static char	*left_c;
	
	count = 1;
	while (count > 0)		
	{
		count = read(fd, buffer, buffer_size);
		buffer[count] = '\0';
		if (left_c)
		{
			stock = ft_strdup(left_c);
			left_c = NULL;
		}
		if (!stock)
			stock = ft_strdup(buffer);
		else
		{
			line = ft_strjoin(stock, buffer);
			stock = ft_strdup(line);
		}
		if (ft_strchr(buffer, '\n') && line)
		{
			left_c = ft_rest(line);
			break ;
		}
	}
	return (line);
}

char	*ft_get_next_line(int fd)
{
	char	*line;

	line = NULL;
	line = ft_fill_line(fd, line, NULL);
	line = ft_extract_line(line);
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
		free(line);
    	}
	close(fd);
	return (0);
}
