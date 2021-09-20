/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 11:54:12 by rgallard          #+#    #+#             */
/*   Updated: 2021/09/20 19:54:31 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_strdel(char **str)
{
	if (str != NULL && *str != NULL)
	{
		free(*str);
		*str = NULL;
	}
}

int	output(int rd, int fd, char **s_mem, char **line)
{
	char	*tmp;

	tmp = ft_strchr(s_mem[fd], '\n');
	if (rd < 0)
		return (-1);
	else if (rd == 0 && (s_mem[fd] == NULL || s_mem[fd][0] == '\0'))
	{
		*line = ft_strdup("");
		ft_strdel(&s_mem[fd]);
		return (0);
	}
	else if (tmp > 0)
	{
		*line = ft_substr(s_mem[fd], 0, tmp - s_mem[fd]);
		tmp = ft_strdup(tmp + 1);
		free(s_mem[fd]);
		s_mem[fd] = tmp;
		return (1);
	}
	else
	{
		*line = ft_strdup(s_mem[fd]);
		ft_strdel(&s_mem[fd]);
		return (0);
	}
}

int	get_next_line(int fd, char **line)
{
	int				rd;
	char			*buffer;
	static char		*s_mem[4096];
	char			*tmp;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!(buffer))
		return (-1);
	s_mem[fd] = s_mem[fd] == NULL ? ft_strdup("") : s_mem[fd];
	rd = read(fd, buffer, BUFFER_SIZE);
	while (rd > 0)
	{
		buffer[rd] = '\0';
		tmp = ft_strjoin(s_mem[fd], buffer);
		free(s_mem[fd]);
		s_mem[fd] = tmp;
		if (ft_strchr(s_mem[fd], '\n'))
			break ;
	}
	free(buffer);
	return (output(rd, fd, s_mem, line));
}
