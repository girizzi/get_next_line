/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girizzi <girizzi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:47:44 by girizzi           #+#    #+#             */
/*   Updated: 2025/02/21 20:20:42 by girizzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*line_malloc(int fd, char *str)
{
	char	*buff;
	ssize_t	dim;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	dim = 1;
	while (!(ft_strchr(str, '\n')) && dim > 0)
	{
		dim = read(fd, buff, BUFFER_SIZE);
		if (dim == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[dim] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*p;
	size_t	i;
	size_t	j;

	if (!str1)
	{
		str1 = (char *)malloc(sizeof(char) * 1);
		str1[0] = '\0';
	}
	if (!str2)
		return (NULL);
	p = (char *)malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!p)
		return (NULL);
	i = 0;
	j = 0;
	while (str1[i])
		p[j++] = str1[i++];
	i = 0;
	while (str2[i])
		p[j++] = str2[i++];
	p[j] = '\0';
	free(str1);
	return (p);
}

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == (char) c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*next_line(char *str)
{
	char	*new;
	size_t	i;

	i = 0;
	if (str[i] == '\0')
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	new = (char *)malloc(sizeof(char) * (i + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		new[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		new[i] = '\n';
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*clean_line(char *line)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(line) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (line[i])
		str[j++] = line[i++];
	str[j] = '\0';
	free(line);
	return (str);
}
