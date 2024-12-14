/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmesa-ke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:09:03 by vmesa-ke          #+#    #+#             */
/*   Updated: 2024/12/14 20:40:55 by vmesa-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*read_fd(int fd, char *saved)
{
	int		b_read;
	char	*readed;

	readed = (char *)malloc(BUFFER_SIZE + 1);
	if (!readed)
		return (free(saved), NULL);
	b_read = 1;
	while (!ft_strchr(saved, '\n') && b_read != 0)
	{
		b_read = read(fd, readed, BUFFER_SIZE);
		if (b_read < 0)
		{
			free (readed);
			free (saved);
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
	static char	*saved;

	if (!saved)
	{
		saved = (char *)malloc(1);
		if (!saved)
			return (NULL);
		saved[0] = '\0';
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!saved || !ft_strchr(saved, '\n'))
	{
		saved = read_fd(fd, saved);
	}
	if (saved == NULL)
		return (NULL);
	line = cut_line(saved);
	saved = lost_chars(saved);
	return (line);
}
