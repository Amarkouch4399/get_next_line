/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouamarko <ouamarko@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:56:48 by ouamarko          #+#    #+#             */
/*   Updated: 2025/06/17 14:19:35 by ouamarko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_extract_line(char *line)
{
	int		i;
	char	*final_line;

	i = 0;
	if (!line)
		return (NULL);
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	final_line = malloc(i + 1);
	if (!final_line)
		return (NULL);
	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		final_line[i] = line[i];
		i++;
	}
	final_line[i] = '\0';
	return (final_line);
}

char	*ft_rest(char *line)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	j = 0;
	if (!line)
		return (NULL);
	while (line[i] != '\n' && line[i])
		i++;
	if (!line[i])
		return (NULL);
	j = i + 1;
	rest = malloc(ft_strlen(line) - i);
	if (!rest)
		return (NULL);
	i = 0;
	while (line[j] != '\0')
	{
		rest[i] = line[j];
		i++;
		j++;
	}
	rest[i] = '\0';
	return (rest);
}
char	*ft_read_and_join(int fd, char *stock)
{
	char	buffer[buffer_size];
	ssize_t	count;
	char	*tmp;

	count = 1;
	while (count > 0)
	{
		count = read(fd, buffer, buffer_size);
		if (count <= 0)
			break ;
		buffer[count] = '\0';
		if (!stock)
			tmp = ft_strdup(buffer);
		else
			tmp = ft_strjoin(stock, buffer);
		stock = tmp;
		ft_free(&tmp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (stock);
}
char	*ft_fill_line(int fd, char *line, char *stock)
{
	static char	*left_c;

	if (left_c)
	{
		stock = ft_strdup(left_c);
		ft_free(&left_c);
		left_c = NULL;
	}
	stock = ft_read_and_join(fd, stock);
	if (stock && ft_strchr(stock, '\n'))
		left_c = ft_rest(stock);
	if (stock)
		line = ft_strdup(stock);
	else
		line = NULL;
	return (ft_free(&stock), line);
}

char	*ft_get_next_line(int fd)
{
	char	*line;

	line = NULL;
	if (fd < 0 || buffer_size <= 0)
		return (NULL);
	line = ft_fill_line(fd, line, NULL);
	line = ft_extract_line(line);
	return (line);
}
int	main()
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Erreur ouverture fichier");
		return (1);
	}
	while (1)
	{
		line = ft_get_next_line(fd);
		if (!line)
			break ;
		printf("%s\n", line);
		ft_free(&line);
	}
	ft_free(&line);
	close(fd);
	return (0);
}
