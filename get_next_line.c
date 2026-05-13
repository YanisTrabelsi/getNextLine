/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytrabels </var/spool/mail/ytrabels>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 16:35:03 by ytrabels          #+#    #+#             */
/*   Updated: 2026/05/13 06:36:33 by ytrabels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;
	int			i;

	if (buf == NULL)
	{
		buf = malloc(BUFFER_SIZE + 1);
		read_fd(buf, fd);
	}
	line = malloc(1);
	*line = '\0';
	i = 0;
	while (i == 0)
	{
		i = flush_buf(&line, &buf, fd);
	}
	return (line);
}

int	main(void)
{
	int	fd;

	fd = open("./fd.txt", O_RDONLY);
	for(int i = 0; i < 34; ++i)
	{
		printf("%s", get_next_line(fd));
	}
	return (0);
}
