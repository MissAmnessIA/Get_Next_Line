/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmesa-ke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:09:03 by vmesa-ke          #+#    #+#             */
/*   Updated: 2024/11/05 17:27:08 by vmesa-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>
char	*get_next_line(int fd)
{
	int b_read = 0;
	char	*readed; 
	char	*line;
	static char	*saved;
	readed = (char *)malloc(BUFFER_SIZE + 1);
	if (!readed)
		return(NULL);
	if (saved == NULL)
	{
		saved = (char *)malloc(1);
		if (!saved)
			return (NULL);
	}
	while (ft_strchr(saved, '\n') == NULL)
	{
		b_read = read(fd, readed, BUFFER_SIZE);
		if (b_read <= 0)
			return(NULL);
		saved = ft_strjoin(saved, readed);
	}
	free (readed);
	line = cut_line(saved);
	saved = lost_chars(saved);
	return(line);
}

int	main(void)
{
	int	fd1 = open("Hola.txt", O_RDONLY);
	int	fd2 = open("Pepe.txt", O_RDONLY);
	int fd3 = open("Lenteja.txt", O_RDONLY);
	char *next_line;
	
	next_line = get_next_line(fd1);
	printf("%s", next_line);
	next_line = get_next_line(fd3);
	printf("%s", next_line);
	next_line = get_next_line(fd1);
	printf("%s", next_line);
	next_line = get_next_line(fd2);
	printf("%s", next_line);
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
