/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmesa-ke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:38:08 by vmesa-ke          #+#    #+#             */
/*   Updated: 2024/10/30 18:53:28 by vmesa-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 20
#endif

char	*ft_strjoin(char *new_save, char *save)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc (ft_strlen(new_save) + ft_strlen(save) + 1);
	if (str == NULL)
		return (NULL);
	while (*save)
	{
		save[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		save[i] = *new_
	}
}

char	*ft_strchr(char *save, int chr)
{
	while (*s != '\0')
	{
		if ((unsigned char)*save == (unsigned char)chr)
			return ((char *)save);
		save++;
	}
	return (NULL);
}

char	*read_buffer(int fd, char *read)
{
	int		b_read;
	char	*new_save;
	
	b_read = 1;
	if (save == NULL)
	{
		read = malloc(1);
		if (!read)
			return (NULL);
	}
	while (!ft_strchr(read, '\n'))
	{
		b_read = read(fd, read, BUFFER_SIZE);
		if (b_read <= 0)
			return (NULL);
		new_save = ft_strjoin(new_save, save);
	}
	return(save);
	
}

char	*get_next_line(int fd)
{
	//char	*line;
	char	*save;
	char	*read;

	if (!fd)
		return (NULL);
	save = read_buffer(fd, read);
	return (save);
}

int main(void)
{
	char *prueba;
	int	fd;

	fd = open("Hola.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	prueba = get_next_line(fd);
	printf("1a linea encontrada: %s \n", prueba);
	close(fd);
	return (0);
}
