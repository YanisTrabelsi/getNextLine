/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytrabels </var/spool/mail/ytrabels>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 16:36:08 by ytrabels          #+#    #+#             */
/*   Updated: 2026/05/13 10:21:35 by ytrabels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>

char	*get_next_line(int fd);
int		ft_strlen(char *str);
void	set_new_buf(char **buf, int index);
int		flush_buf(char **line, char **buf, int fd);
void	write_realloc_line(char **line, char c);
ssize_t	read_fd(char *buf, int fd);

#endif
