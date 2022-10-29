/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srvorkap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 23:41:15 by srvorkap          #+#    #+#             */
/*   Updated: 2019/11/12 22:02:37 by srvorkap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_read_line(char **tab, char **line, int fd)
{
	int		i;
	char	*temp;

	i = 0;
	while (tab[fd][i] != '\0' && tab[fd][i] != '\n')
		i++;
	*line = ft_strsub(tab[fd], 0, i);
	if (tab[fd][i] == '\n')
	{
		temp = ft_strdup(&tab[fd][i + 1]);
		free(tab[fd]);
		tab[fd] = temp;
		if (tab[fd][0] == '\0')
			ft_strdel(&tab[fd]);
	}
	else
		ft_strdel(&tab[fd]);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	int			reader;
	char		*temp;
	char		buf[BUFF_SIZE + 1];
	static char	*tab[FD_LIMIT];

	if (fd < 0 || fd > FD_LIMIT || BUFF_SIZE <= 0 ||
			line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	while ((reader = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[reader] = '\0';
		if (!tab[fd])
			tab[fd] = ft_strdup(buf);
		else
		{
			temp = ft_strjoin(tab[fd], buf);
			free(tab[fd]);
			tab[fd] = temp;
		}
		if (ft_strchr(tab[fd], '\n'))
			break ;
	}
	if (tab[fd] == NULL && reader == 0)
		return (0);
	return (ft_read_line(tab, line, fd));
}
