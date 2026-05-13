/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytrabels </var/spool/mail/ytrabels>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 16:42:34 by ytrabels          #+#    #+#             */
/*   Updated: 2026/05/13 06:33:44 by ytrabels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		++len;
		++str;
	}
	return (len);
}

void	write_realloc_line(char **line, char c)
{
	char	*temp;
	int		i;

	i = 0;
	temp = malloc(ft_strlen(*line) + 2);
	if (!temp)
		return ;
	while ((*line)[i])
	{
		temp[i] = (*line)[i];
		++i;
	}
	free(*line);
	*line = temp;
	(*line)[i++] = c;
	(*line)[i] = '\0';
}

int	    flush_buf(char **line, char **buf, int fd)
{
    int i;

    i = 0;
    while ((*buf)[i] && (*buf)[i] != '\n')
        write_realloc_line(line, (*buf)[i++]);
    if ((*buf)[i] == '\n')
	{
		write_realloc_line(line, (*buf)[i]);
		set_new_buf(buf, i);
		return (1);
	}
	if ((*buf)[i])
		set_new_buf(buf, i);
	else
	{
		free(*buf);
		*buf = malloc(BUFFER_SIZE + 1);
		read_fd(*buf, fd);
	}
	return (0);
}

void	set_new_buf(char **buf, int index)
{
	int		i;
	char	*temp;

	i = 0;
	temp = malloc(ft_strlen(*buf) - index);
	if (!temp)
		return ;
	++index;
	while((*buf)[index])
		temp[i++] = (*buf)[index++];
	temp[i] = '\0';
	free(*buf);
	*buf = temp;
}

int	read_fd(char *buf, int fd)
{
	int	read_res;

	read_res = read(fd, buf, BUFFER_SIZE);
	buf[read_res] = '\0';
	return (read_res);
}
