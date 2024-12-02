/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmesa-ke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:06:22 by vmesa-ke          #+#    #+#             */
/*   Updated: 2024/11/15 16:06:26 by vmesa-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*read_fd(int fd, char *saved);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *saved, char *readed);
int		ft_strlen(char *str);
char	*cut_line(char	*saved);
char	*lost_chars(char *saved);
#endif