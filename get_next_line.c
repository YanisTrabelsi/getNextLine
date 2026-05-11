/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytrabels </var/spool/mail/ytrabels>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 16:35:03 by ytrabels          #+#    #+#             */
/*   Updated: 2026/05/11 05:40:11 by ytrabels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	remains_handler(char *remains, char *line, int *i)
{
	static int	k;

	while (remains[k] && remains[k] != '\n')
	{
		line[(*i)++] = remains[k++];
		if (remains[k] == '\n')
		{
			++k;
			return (1);
		}
	}
	return (0);
}

void	write_handler(int fd, char **line, char *remains, int *i)
{
	int			is_n;
	char		*buf;
	int			bytes;
	static char	*temp;

	buf = malloc(BUFFER_SIZE + 1);
	if (temp)
		load_remains(remains, temp);
	is_n = remains_handler(remains, *line, i);
	if (is_n != 0)
	{
		while (is_n != 1)
		{
			bytes = read(fd, buf, BUFFER_SIZE);
			if (bytes > 0)
				buf[bytes] = '\0';
			realloc_line(line, buf);
			is_n = write_buf(buf, *line, remains, i);
		}
		temp = save_remains(remains);
	}
}

char	*get_next_line(int fd)
{
	static char	*line;
	static char	*remains;
	static int	i;

	remains = malloc(BUFFER_SIZE);
	i = 0;
	write_handler(fd, &line, remains, &i);
	line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

int	main(void)
{
	int	fd;
	int	i;

	fd = open("./fd.txt", O_RDONLY);
	i = 10;
	while (i > 0)
	{
		printf(get_next_line(fd));
		--i;
	}
	return (0);
}
