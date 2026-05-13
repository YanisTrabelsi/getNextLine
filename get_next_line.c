/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytrabels </var/spool/mail/ytrabels>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 16:35:03 by ytrabels          #+#    #+#             */
/*   Updated: 2026/05/13 10:22:22 by ytrabels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	init_buf(int fd, char **buf)
{
	if (*buf == NULL)
	{
		*buf = malloc(BUFFER_SIZE + 1);
		if (!*buf)
			return (-1);
		(*buf)[0] = '\0';
		if (read_fd(*buf, fd) < 0)
		{
			free(*buf);
			*buf = NULL;
			return (-1);
		}
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;
	ssize_t		i;

	if (init_buf(fd, &buf) == -1)
		return (NULL);
	line = malloc(1);
	*line = '\0';
	i = 0;
	while (i == 0)
		i = flush_buf(&line, &buf, fd);
	if (i == -2)
		return (NULL);
	if (i == -1 && *line == '\0')
	{
		free(buf);
		buf = NULL;
		return (NULL);
	}
	return (line);
}

/*
int	main(void)
{
	int	fd;

	fd = open("./fd.txt", O_RDONLY);
	for (int i = 0; i < 18; ++i)
		printf("%s", get_next_line(fd));
	return (0);
}*/
