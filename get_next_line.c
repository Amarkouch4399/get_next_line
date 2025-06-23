/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouamarko <ouamarko@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:56:48 by ouamarko          #+#    #+#             */
/*   Updated: 2025/06/21 20:04:11 by ouamarko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_extract_line(char *line)
{
	int		i;
	int		j;
	char	*final_line;

	i = 0;
	if (!line)
		return (NULL);
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\n')
		i++;
	final_line = malloc(i + 1);
	if (!final_line)
		return (NULL);
	j = i;
	i = 0;
	while (i < j && line[i] != '\0')
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
		return (ft_free(&line), NULL);
	while (line[i] != '\n' && line[i])
		i++;
	if (!line[i])
		return (NULL);
	j = i + 1;
	if (line[j] == '\0')
		return (NULL);
	rest = malloc(ft_strlen(line) - j + 1);
	if (!rest)
		return (NULL);
	i = 0;
	while (line[j] != '\0')
		rest[i++] = line[j++];
	rest[i] = '\0';
	return (rest);
}

char	*ft_read_and_join(int fd, char *stock)
{
	char	*buffer;
	ssize_t	count;
	char	*tmp;

	count = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (count > 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count <= 0)
			break ;
		buffer[count] = '\0';
		if (!stock)
			tmp = ft_strdup(buffer);
		else
			tmp = ft_strjoin(stock, buffer);
		if (stock)
			free(stock);
		stock = tmp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (ft_free(&buffer), stock);
}

char	*get_next_line(int fd)
{
	static char	*left_c;
	char		*line;
	char		*new_left;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	left_c = ft_read_and_join(fd, left_c);
	if (!left_c)
		return (NULL);
	line = ft_extract_line(left_c);
	/*
	 * if (!line || line[0] == '\0')
	 * {
	 * ft_free(&line);
	 * return (NULL);
	 * }
	*/
	new_left = ft_rest(left_c);
	if (!new_left)
		ft_free(&left_c);
	else
	{
		ft_free(&left_c);
		left_c = new_left;
	}
	return (line);
}
/*
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
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("%s", line);
		ft_free(&line);
	}
	ft_free(&line);
	close(fd);
	return (0);
}
*/
