/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmesa-ke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:33:19 by vmesa-ke          #+#    #+#             */
/*   Updated: 2024/11/05 17:16:44 by vmesa-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 20
#endif

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *saved, char *readed);
int		ft_strlen(char *str);
char	*cut_line(char	*saved);
char	*lost_chars(char *saved);
