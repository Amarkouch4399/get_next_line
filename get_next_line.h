/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouamarko <ouamarko@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:57:07 by ouamarko          #+#    #+#             */
/*   Updated: 2025/06/13 11:52:41 by ouamarko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

#ifndef buffer_size
#define buffer_size 5
#endif

char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(char *src);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char const *s);
char	*ft_extract_line(char *line);
char	*ft_rest(char *line);
char	*ft_fill_line(int fd, char *line, char *stock);
char	*ft_read_all_if_small(int fd);

#endif
