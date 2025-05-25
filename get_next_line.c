/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouamarko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:06:42 by ouamarko          #+#    #+#             */
/*   Updated: 2025/05/25 19:18:42 by ouamarko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
char	*ft_get_next_line(int fd)
{
	static int	buffer_size;
	static char	*buffer[buffer_size];

	if (fd < 0)
		return (-1);
	


}
int	ft_buff_size(int fd)
{
	int	i;

	i = 0;
	if (fd < 0)
		return (-1);
	while (fd[i] != '\n' ||)
		i++;
	return (i);
}
*/
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int	main()
{
	int	fd;
	char	*c = "OUSSAMA\namarkouch\n123456\n123";

	fd = open("test.txt", O_CREAT | O_WRONLY);
	if (fd < 0)
		return(-1);
	printf("%d\n", fd);
}
