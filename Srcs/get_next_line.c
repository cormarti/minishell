/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 09:41:15 by cormarti          #+#    #+#             */
/*   Updated: 2018/03/22 23:15:00 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

static int		ft_allfree(t_list **rl, char **buf, char **rest, int state)
{
	if (state == 0)
	{
		free(*buf);
		free(*rl);
		free(*rest);
	}
	else if (state == 3)
	{
		free(*buf);
		free(*rl);
	}
	else if (state == 1)
		free(*rl);
	return (0);
}

static char		*ft_trunccstr(char **str, int c)
{
	char		*new;
	char		*tmp;

	new = NULL;
	new = ft_strnew(ft_strclen(*str, c) + 2);
	ft_memccpy(new, *str, c, ft_strclen(*str, c));
	tmp = NULL;
	if (ft_strchr(*str, '\n'))
	{
		tmp = ft_strnew(ft_strlen(*str) - ft_strclen(*str, '\n') + 1);
		tmp = ft_strcpy(tmp, ft_strchr(*str, '\n') + 1);
		free(*str);
		*str = NULL;
		*str = ft_strnew(ft_strlen(tmp) + 1);
		*str = ft_strcpy(*str, tmp);
		free(tmp);
		tmp = NULL;
	}
	if (ft_strcmp(new, *str) == 0)
	{
		free(*str);
		*str = NULL;
	}
	return (new);
}

static void		ft_catalloc(char **line, char *src, int *cpd, int buf)
{
	char		*tmp;
	int			len;

	if (ft_strclen(src, '\0') > 0)
		*cpd += 1;
	len = (*line) ? ft_strlen(*line) : 0;
	len += 1 + ft_strlen(src);
	tmp = ft_strnew(len + 1);
	if (*line)
		tmp = ft_strcpy(tmp, *line);
	tmp = ft_strcat(tmp, src);
	if (*line)
		free(*line);
	*line = ft_memalloc(ft_strlen(tmp) + 2);
	*line = ft_strcpy(*line, tmp);
	if (tmp)
		free(tmp);
	if (!buf)
	{
		free(src);
		src = NULL;
	}
}

int				ft_bptn(char **line, char **rest, t_list **rl)
{
	t_list		*toto;

	toto = *rl;
	toto = (t_list*)malloc(sizeof(t_list));
	toto->buf = ft_strnew(GNL_BUFF_SIZE + 1);
	toto->cpd = 0;
	if (!line)
		return (-1);
	*line = NULL;
	if (*rest)
	{
		if (*rest[0] == '\n' && ft_strclen(*rest, '\0') == 1)
		{
			*line = malloc(sizeof(char) * 1);
			*line[0] = '\0';
			free(*rest);
			*rest = NULL;
			return (ft_allfree(&toto, &toto->buf, &(*rest), 3) == 0 ? 1 : 1);
		}
		ft_catalloc(&(*line), ft_trunccstr(&(*rest), '\n'), &toto->cpd, 0);
		if (*rest)
			return (ft_allfree(&toto, &toto->buf, &(*rest), 3) == 0 ? 1 : 1);
	}
	*rl = toto;
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char	*rest;
	t_list		*rl;

	rl = NULL;
	if (ft_bptn(&(*line), &rest, &rl) != 0)
		return (((!line) || fd < 0) ? -1 : 1);
	while ((rl->ret = read(fd, rl->buf, GNL_BUFF_SIZE)) > 0)
	{
		rl->buf[rl->ret] = '\0';
		if (ft_strchr(rl->buf, '\n'))
		{
			ft_catalloc(&(*line), ft_trunccstr(&rl->buf, '\n'), &rl->cpd, 0);
			if (R && rl->buf[0] && (rest = ft_memalloc(ft_strlen(rl->buf) + 1)))
				rest = ft_strcpy(rest, rl->buf);
			if (rl->buf)
				free(rl->buf);
			return (ft_allfree(&rl, &rl->buf, &rest, 1) == 0 ? 1 : 1);
		}
		ft_catalloc(&(*line), rl->buf, &rl->cpd, 1);
	}
	if (rl->ret < 0)
		return (ft_allfree(&rl, &rl->buf, &rest, 0) == 0 ? -1 : -1);
	if (rl->cpd < 1)
		return (ft_allfree(&rl, &rl->buf, &rest, 0));
	return (1);
}
