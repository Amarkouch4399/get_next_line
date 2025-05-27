/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouamarko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:06:42 by ouamarko          #+#    #+#             */
/*   Updated: 2025/05/27 19:31:40 by ouamarko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_next_line(int fd)
{
	char	*str;
	char	c;
	static ssize_t sz;
	int	i;

	i = 0;
	str = malloc(sizeof(char) * buffer_size);
	while((sz = read(fd, &c, 1) > 0))
	{
		str[i] = c;
		if (str[sz] == '\n')
			break ;
		i++;
	}
	 if (sz <= 0 && i == 0)
	 {
		 free(str);
		 return (NULL);
	 }
	str[i] = '\0';
	return (str);
}
int	main()
{
	int	fd;
	char	*str ="oussama\namarkouch";

	fd = open("test.txt", O_CREAT | O_WRONLY);
	while ((str = ft_get_next_line(fd)) != NULL)
	{
		printf("%s", str);
		free(str);
	}
	if (fd < 0)
		return(-1);
	close(fd);
	return (0);
}
