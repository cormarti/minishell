/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 09:13:50 by cormarti          #+#    #+#             */
/*   Updated: 2018/03/25 15:22:42 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

char		*home_path(char **envp)
{
	int		index;

	if ((index = str_index(envp, "HOME=")) == -1)
		return (NULL);
	return (cut_strchr(ft_strdup(envp[index]), '='));
}

char		*old_path(char **envp)
{
	int		index;

	if ((index = str_index(envp, "OLDPWD=")) == -1)
		return (NULL);
	return (cut_strchr(ft_strdup(envp[index]), '='));
}

static int	cd_err(int status, char *path)
{
	if (status == 1)
		ft_putendl("cd: cannot access current dir informations");
	else if (status == 2)
	{
		ft_putstr("cd: ");
		if (path)
			ft_putstr(path);
		ft_putendl(": No such file or directory");
	}
	else if (status == 3)
		ft_putendl("cd: HOME var is not set");
	else if (status == 4)
		ft_putendl("cd: OLD_PWD var is not set");
	return (0);
}

static char	**update_env(char *old, char **tab)
{
	char	curr_dir[1024];
	char	*dir;
	int		i;

	i = 0;
	old = ft_strjoin("OLDPWD=", old);
	dir = getcwd(curr_dir, 1024);
	dir = ft_strjoin("PWD=", curr_dir);
	while (tab[i])
	{
		if (ft_strncmp(tab[i], "OLDPWD=", 7) == 0)
		{
			free(tab[i]);
			tab[i] = ft_strdup(old);
		}
		else if (ft_strncmp(tab[i], "PWD=", 4) == 0)
		{
			free(tab[i]);
			tab[i] = ft_strdup(dir);
		}
		i++;
	}
	free(old);
	free(dir);
	return (tab);
}

int			ft_cd(char *path, char ***envp)
{
	char	curr_dir[1024];
	char	*dir;
	char	**env;
	char	*fullpath;

	env = *envp;
	if (!path)
		return (cd_err(1, path));
	if (!(dir = (getcwd(curr_dir, 1024) != NULL ?
		getcwd(curr_dir, 1024) : ft_strdup(""))))
		return (cd_err(1, path));
	if (path && path[0] == '/')
		fullpath = ft_strdup(path);
	else
		fullpath = ft_strjoinf(ft_strjoin(dir, "/"), path, 1);
	if (chdir(fullpath) != 0)
	{
		free(fullpath);
		return (cd_err(2, path));
	}
	*envp = update_env(dir, *envp);
	free(fullpath);
	return (1);
}
