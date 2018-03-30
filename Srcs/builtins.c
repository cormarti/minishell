/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 08:42:23 by cormarti          #+#    #+#             */
/*   Updated: 2018/03/29 23:59:51 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

static void	call_cd(char **argv, char ***envp)
{
	char	*path;

	path = NULL;
	if (!argv[1])
	{
		path = home_path(*envp);
		ft_cd(path, envp);
		free(path);
	}
	else if (ft_strcmp(argv[1], "-") == 0)
	{
		free(argv[1]);
		argv[1] = old_path(*envp);
		ft_cd(argv[1], envp);
	}
	else
		ft_cd(argv[1], envp);
}

void		call_builtin(char **argv, char ***envp)
{
	if (ft_strcmp(argv[0], g_builtin[0]) == 0)
		ft_env(argv, *envp);
	else if (ft_strcmp(argv[0], g_builtin[1]) == 0)
		ft_lst_setenv(argv, envp);
	else if (ft_strcmp(argv[0], g_builtin[2]) == 0)
		ft_lst_unsetenv(argv, envp);
	else if (ft_strcmp(argv[0], g_builtin[3]) == 0)
		ft_exit();
	else if (ft_strcmp(argv[0], g_builtin[4]) == 0)
		call_cd(argv, envp);
	else if (ft_strcmp(argv[0], g_builtin[5]) == 0)
		ft_echo(argv);
}
