/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytrabels </var/spool/mail/ytrabels>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 16:36:08 by ytrabels          #+#    #+#             */
/*   Updated: 2026/05/11 04:13:48 by ytrabels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
char	*get_next_line(int fd);
void	realloc_line(char **lineptr, char *buf);
int		ft_strlen(char *str);
int		write_buf(char *buf, char *line, char *remains, int	*k);
char	*save_remains(char *remains);
void	load_remains(char *remains, char *temp);



#endif

