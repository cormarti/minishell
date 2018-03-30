/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 23:55:50 by cormarti          #+#    #+#             */
/*   Updated: 2018/03/29 23:51:12 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

void		print_currpath(void)
{
	char	curr_dir[1024];
	char	*dir;

	dir = getcwd(curr_dir, 1024);
	ft_putstr(dir);
	ft_putstr("$> ");
}

char		*cut_strchr(char *str, int c)
{
	int		i;
	char	*new;

	i = 0;
	new = ft_strdup(ft_strchr(str, c) + 1);
	free(str);
	return (new);
}

int			str_index(char **envp, char *cmp)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], cmp, ft_strlen(cmp)) == 0)
			break ;
		i++;
	}
	return (envp[i] ? i : -1);
}

static char	**get_path(char *cmd, char **envp)
{
	char	**path;
	int		i;

	if ((i = str_index(envp, "PATH=")) != -1)
	{
		path = ft_strsplit(envp[i], ':');
		path[0] = cut_strchr(path[0], '=');
		path = ft_tab_insert(cmd, &path);
	}
	else
	{
		path = (char**)malloc(sizeof(char*) * 2);
		path[0] = ft_strdup(cmd);
		path[1] = NULL;
	}
	i = 0;
	while (path[i])
	{
		if (path[i + 1])
			path[i] = ft_strjoinf(ft_strjoinf(path[i], "/", 1), cmd, 1);
		i++;
	}
	return (path);
}

void		sys_cmd(char **argv, char **envp)
{
	char	**path;
	int		i;

	i = 0;
	path = get_path(argv[0], envp);
	while (path && path[i])
	{
		if (access(path[i], X_OK) == 0)
			break ;
		i++;
	}
	if (path && path[i])
		sys_fork(path[i], argv, envp);
	else
	{
		ft_putstr(argv[0]);
		ft_putendl(": command not found");
	}
	free_arr(path);
}
