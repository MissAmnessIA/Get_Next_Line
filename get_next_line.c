/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmesa-ke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:09:03 by vmesa-ke          #+#    #+#             */
/*   Updated: 2024/11/13 17:31:44 by vmesa-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*read_fd(int fd, char *saved)
{
	int		b_read;
	char	*readed;

	b_read = 1;
	while (!ft_strchr(saved, '\n') && b_read != 0)
	{
		readed = (char *)malloc(BUFFER_SIZE + 1);
		if (!readed)
			return (free(saved),NULL);
		b_read = read(fd, readed, BUFFER_SIZE);
		if (b_read <= 0)
		{
			free (readed);
			free (saved);
			return (NULL);
		}
		readed[b_read] = '\0';
		saved = ft_strjoin(saved, readed);
	}
	return (saved);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*saved;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!saved || !ft_strchr(saved, '\n'))
	{
		if (!saved)
		{
			saved = (char *)malloc(1);
			if (!saved)
				return (NULL);
		}
		saved = read_fd(fd, saved);
	}
	if (saved == NULL)
		return (NULL);
	line = cut_line(saved);
	saved = lost_chars(saved);
	return (line);
}
