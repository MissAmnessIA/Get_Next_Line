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
#include <stdio.h>

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
	static char	*saved;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!saved || !ft_strchr(saved, '\n'))
		saved = read_fd(fd, saved);
	if (saved == NULL)
		return (NULL);
	line = cut_line(saved);
	saved = lost_chars(saved);
	return (line);
}

/*int	main(void)
{
	int		fd1;
	char	*next_line;

	fd1 = open("Hola.txt", O_RDONLY);
	while (1)
	{
		next_line = get_next_line(fd1);
		printf("%s \n", next_line);
		if (next_line == NULL)
			break ;
	}
	close(fd1);
	return (0);
}*/
