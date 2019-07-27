/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 12:39:36 by cdubuque          #+#    #+#             */
/*   Updated: 2019/04/13 21:51:33 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*cpyjoin(char *buf, char *tmp)
{
	char	*s;
	size_t	i;

	i = ft_strlen(buf);
	if (tmp != NULL)
	{
		s = ft_strjoin(tmp, buf);
		buf[0] = '\0';
		free(tmp);
		return (s);
	}
	s = ft_strdup(buf);
	buf[0] = '\0';
	return (s);
}

static int		line_ret(char **line, char **tmp, int res)
{
	if (res == 0 && ft_strlen(*tmp) > 0)
	{
		*line = *tmp;
		*tmp = NULL;
		return (1);
	}
	free(*tmp);
	return (res);
}

static void		*read_line(char **line, char **tmp, char **s)
{
	size_t		r;

	r = 0;
	if ((ft_strchr(*tmp, '\n') + 1) != NULL)
	{
		*s = ft_strnew(BUFF_SIZE);
		ft_strncpy(*s, ft_strchr(*tmp, '\n') + 1, BUFF_SIZE);
	}
	while (tmp[0][r] != '\n')
		r++;
	if (!(*line = (char *)malloc(sizeof(char) * (r + 1))))
		return (NULL);
	ft_strncpy(*line, *tmp, r);
	line[0][r] = '\0';
	free(*tmp);
	return (NULL);
}

static void		remainder(char **s, char **tmp)
{
	if (*s != NULL)
	{
		ft_strncpy(*tmp, *s, BUFF_SIZE);
		free(*s);
		*s = NULL;
	}
}

int				get_next_line(const int fd, char **line)
{
	static char	*s[4864];
	int			res;
	char		buf[BUFF_SIZE + 1];
	char		*tmp;

	if (fd < 0 || BUFF_SIZE < 1 || !line || BUFF_SIZE > 10000000 || fd > 4864)
		return (-1);
	tmp = ft_strnew(BUFF_SIZE + 1);
	remainder(&s[fd], &tmp);
	if (tmp[BUFF_SIZE] == '\0')
	{
		while (!(ft_strchr(tmp, '\n')) || tmp == NULL)
		{
			res = read(fd, buf, BUFF_SIZE);
			if (res < 1)
				return (line_ret(line, &tmp, res));
			buf[res] = '\0';
			tmp = cpyjoin(buf, tmp);
		}
	}
	read_line(line, &tmp, &s[fd]);
	return (1);
}
