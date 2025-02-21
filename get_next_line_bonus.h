/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girizzi <girizzi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:42:54 by girizzi           #+#    #+#             */
/*   Updated: 2025/02/21 20:54:34 by girizzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 24
# endif

# ifndef MAX_FD
#  define MAX_FD 1048576
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*line_malloc(int fd, char *str);
char	*next_line(char *str);
char	*clean_line(char *line);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char *str1, char *str2);

#endif