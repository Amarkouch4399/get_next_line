/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouamarko <ouamarko@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:56:48 by ouamarko          #+#    #+#             */
/*   Updated: 2025/06/03 19:14:40 by ouamarko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_fill_line(int fd, char *left_c, char *line)
{
	int	i;
	ssize_t	count;
	char	temp[buffer_size + 1];

	temp[buffer_size + 1] = '\0';
	if (left_c)
		left_c = ft_strdup(temp);
	i++;
	 while (ft_strchr(line, '\n') )
	 {
		 count = read(fd, temp, buffer_size);
		printf("ligne %s", temp);
	 }
	return (line);
}

char	*ft_get_next_line(int fd)
{
	char	*line;
	ssize_t count;

	line = malloc(buffer_size);
	if (!line)
		return (NULL);
	line = ft_fill_line(fd, NULL, line);	
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
		printf("ligne %s", ft_get_next_line(fd));
		printf("\n");
		free(line);
	}
	close(fd);
	return (0);
}
