/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmesa-ke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:05:29 by vmesa-ke          #+#    #+#             */
/*   Updated: 2024/11/15 16:05:34 by vmesa-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

char	*read_fd(int fd, char *saved)
{
	int		b_read;
	char	*readed;

	readed = (char *)malloc(BUFFER_SIZE + 1);
	if (!readed)
		return (NULL);
	if (!saved)
		saved = (char *)malloc(1);
	b_read = 1;
	while (!ft_strchr(readed, '\n') && b_read != 0)
	{
		b_read = read(fd, readed, BUFFER_SIZE);
		if (b_read <= 0)
		{
			free (readed);
			return (NULL);
		}
		readed[b_read] = '\0';
		saved = ft_strjoin(saved, readed);
	}
	free(readed);
	return (saved);
}
char	*get_next_line(int fd)
{
	char		*line;
	static char	*saved[30798];
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!saved[fd] || !ft_strchr(saved[fd], '\n'))
		saved[fd] = read_fd(fd, saved[fd]);
	if (saved[fd] == NULL)
		return (NULL);
	line = cut_line(saved[fd]);
	saved[fd] = lost_chars(saved[fd]);
	return (line);
}