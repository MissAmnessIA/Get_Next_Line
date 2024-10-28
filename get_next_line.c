/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmesa-ke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:37:29 by vmesa-ke          #+#    #+#             */
/*   Updated: 2024/10/28 19:42:16 by vmesa-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	static char	*save;
	char		*next_line;

	if (fd <= 0)
		return (NULL);
	save = read_buffer(save, fd);
}

char	*read_buffer(char *save, int fd)
{
	char	*tmp;
	int		b_read;
	int		count;

	if (!save)
		save = ft_calloc(1, 1);
	tmp = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!tmp)
		return (NULL);
	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, tmp, BUFFER_SIZE);
		if (b_read <=0)
			return (NULL);
		save = ft_strjoin(save, tmp);
		if (ft_strchr(save, '\n'))
			break ;
	}
}
