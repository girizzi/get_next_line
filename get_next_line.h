/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girizzi <girizzi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:42:54 by girizzi           #+#    #+#             */
/*   Updated: 2025/02/21 20:21:29 by girizzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*malloc_line(int fd, char *str);
char	*next_line(char *str);
char	*clean_line(char *line);
char	*ft_strjoin(char *str1, char *str2);
char		*ft_strchr(const char *str, int c);
size_t	ft_strlen(const char *str);

#endif