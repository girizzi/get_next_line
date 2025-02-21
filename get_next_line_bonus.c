/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girizzi <girizzi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:45:11 by girizzi           #+#    #+#             */
/*   Updated: 2025/02/21 20:49:48 by girizzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer[4096];

	line = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer[fd] = line_malloc(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = next_line(buffer[fd]);
	buffer[fd] = clean_line(buffer[fd]);
	return (line);
}

/*
int 	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (0);
}
*/