/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 11:54:12 by rgallard          #+#    #+#             */
/*   Updated: 2021/09/22 18:54:17 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
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
	int	i;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	if (s_mem[fd] == NULL)
		s_mem[fd] = ft_strdup("");
	rd = read(fd, buffer, BUFFER_SIZE);
	while (rd > 0)
	{
		buffer[rd] = '\0';
		tmp = ft_strjoin(s_mem[fd], buffer);
		free(s_mem[fd]);
		s_mem[fd] = tmp;
		if (ft_strchr(s_mem[fd], '\n'))
			break ;
		rd = read(fd, buffer, BUFFER_SIZE);
	}
	i = -1;
	free(buffer);
	return (output(rd, fd, s_mem, line));
}
*/

int		ft_new_line(char **s, char **line, int fd, int ret)
{
	char	*tmp;
	int		len;

	len = 0;
	while (s[fd][len] != '\n' && s[fd][len] != '\0')
		len++;
	if (s[fd][len] == '\n')
	{
		*line = ft_strsub(s[fd], 0, len);
		tmp = ft_strdup(s[fd] + len + 1);
		free(s[fd]);
		s[fd] = tmp;
		if (s[fd][0] == '\0')
			ft_strdel(&s[fd]);
	}
	else if (s[fd][len] == '\0')
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*s[255];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strnew(1);
		tmp = ft_strjoin(s[fd], buf);
		free(s[fd]);
		s[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
		return (0);
	return (ft_new_line(s, line, fd, ret));
}
