/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytrabels </var/spool/mail/ytrabels>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 16:42:34 by ytrabels          #+#    #+#             */
/*   Updated: 2026/05/11 04:39:14 by ytrabels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		++count;
		++i;
	}
	return (count);
}

void	realloc_line(char **lineptr, char *buf)
{
	char	*temp;
	int		i;

	temp = malloc(ft_strlen(*lineptr) + ft_strlen(buf) + 1);
	if (!temp)
		return ;
	i = 0;
	while (*lineptr && (*lineptr)[i])
	{
		temp[i] = (*lineptr)[i];
		++i;
	}
	temp[i] = '\0';
	free(*lineptr);
	*lineptr = temp;
}

int	write_buf(char *buf, char *line, char *remains, int	*k)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
		{
			++i;
			while(buf[i])
				remains[j++] = buf[i++];
			remains[j] = '\0';
			return (1);
		}
		line[(*k)++] = buf[i++];
	}
	line[*k] = '\0';
	return (0);
}

char	*save_remains(char *remains)
{	
	static char	*temp;
	int			i;

	temp = malloc(ft_strlen(remains) + 1);
	i = 0;
	while (remains[i])
	{
		temp[i] = remains[i];
		++i;
	}
	temp[i] = '\0';
	return (temp);
}

void	load_remains(char *remains, char *temp)
{
	int	i;

	i = 0;
	while (temp[i])
	{
		remains[i] = temp[i];
		i++;
	}
	remains[i] = '\0';
}
