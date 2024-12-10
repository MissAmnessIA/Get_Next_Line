/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmesa-ke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:33:05 by vmesa-ke          #+#    #+#             */
/*   Updated: 2024/11/13 17:21:59 by vmesa-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*lost_chars(char	*saved)
{
	char	*new_save;
	int		i;
	char	*temp;

	i = 0;
	temp = saved;
	while (*temp != '\n')
		temp++;
	temp++;
	while (temp[i])
		i++;
	new_save = (char *)malloc(i + 1);
	if (!new_save)
		return (free(saved), NULL);
	i = 0;
	while (*temp)
	{
		new_save[i] = *temp;
		i++;
		temp++;
	}
	free(saved);
	new_save[i] = '\0';
	return (new_save);
}

char	*ft_strjoin(char *saved, char *readed)
{
	char	*joined;
	int		i;
	char	*temp;

	i = 0;
	temp = saved;
	joined = (char *)malloc(ft_strlen(saved) + ft_strlen(readed) + 1);
	while (*temp)
	{
		joined[i] = *temp;
		i++;
		temp++;
	}
	temp = readed;
	while (*temp)
	{
		joined[i] = *temp;
		i++;
		temp++;
	}
	free(saved);
	free(readed);
	joined[i] = '\0';
	return (joined);
}

char	*cut_line(char	*saved)
{
	char	*line;
	int		i;

	i = 0;
	if (saved[i] == '\0')
		return (NULL);
	while (saved[i] != '\n' && saved[i])
		i++;
	line = (char *)malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (saved[i] && saved[i] != '\n')
	{
		line[i] = saved[i];
		i++;
	}
	if (saved[i] == '\n')
	{
		line[i] = '\n';
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
	return (i);
}
