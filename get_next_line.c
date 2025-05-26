/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouamarko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:06:42 by ouamarko          #+#    #+#             */
/*   Updated: 2025/05/26 18:45:14 by ouamarko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	ft_strlen(int fd)
{
	int	i;
	ssize_t	sz;
	char	*s;
	i = 0;
	while (sz = read(fd, &s[i] ,i) != EOF)
		i++;
	return (i);
}
char	*ft_get_next_line(int fd)
{
	int	buffer_size;
	static const char	*buffer[1000];

	buffer_size = 0;
	buffer_size = ft_strlen(fd);
	return (0);
}
int	main()
{
	int	fd;
	static char	*c = "OUSSAMA\namarkouch\n123456\n123";

	fd = open("test.txt", O_CREAT | O_WRONLY);
	if (fd < 0)
		return(-1);
	ft_get_next_line(fd);
	printf("%d\n", ft_strlen(fd));
}
