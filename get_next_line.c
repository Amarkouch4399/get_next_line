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

char	*ft_fill_line_buffer(int fd, char *left_c, char *line)
{
	int	i;
	ssize_t	count;
	char	temp[buffer_size + 1];

	i = 0;
	while (count = read(fd,temp, buffer_size) > 0)
	{
		temp[buffer_size + 1] = '\0';
		if (!left_c)
			left_c = ft_strdup(temp);
		i++;
		printf("%s", left_c);
		printf("\n");
		if (temp[i] == '\n')
			break ;
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
		printf("%s", ft_get_next_line(fd));
		printf("\n");
		free(line);
	}
	close(fd);
	return (0);
}
