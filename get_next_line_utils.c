/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmesa-ke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:33:05 by vmesa-ke          #+#    #+#             */
/*   Updated: 2024/11/05 17:14:39 by vmesa-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if ((unsigned char)*s == (unsigned char)c)
			return((char *)s);
		s++;
	}
	return (NULL);
}

char	*lost_chars(char	*saved)
{
	char	*new_save;
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (*saved != '\n')
		saved++;
	saved++;
	while (*saved)
	{
		saved++;
		count++;
	}
	saved -= count;
	new_save = (char *)malloc(i + 1);
	if (!new_save)
		return(NULL);
	while(*saved)
	{
		new_save[i] = *saved;
		i++;
		saved++;
	}
	new_save[i] = '\0';
	return(new_save);
}

char	*ft_strjoin(char *saved, char *readed)
{
	char	*joined;
	int	i;

	i = 0;
	joined = (char *)malloc(ft_strlen(saved) + ft_strlen(readed) + 1);
	while (*saved)
	{
		joined[i] = *saved;
		i++;
		saved++;
	}
	while (*readed)
	{
		joined[i] = *readed;
		i++;
		readed++;
	}
	joined[i] = '\0';
	return (joined);
}

char	*cut_line(char	*saved)
{
	char	*line;
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (saved[count] != '\n')
		count++;
	line = (char *)malloc(count + 2);
	if (!line)
		return (NULL);
	while (i <= count)
	{
		line[i] = saved[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

int	ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
		i++;
	return(i);
}
