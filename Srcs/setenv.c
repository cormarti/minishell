/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 05:50:23 by cormarti          #+#    #+#             */
/*   Updated: 2018/03/21 13:50:21 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

static int	setenv_err(int status)
{
	if (status == 1)
		ft_putendl("Syntax error: '=' is missing.");
	else if (status == 2)
		ft_putendl("Syntax error: no name specified");
	return (0);
}

int			ft_setenv(char *str, char ***envp)
{
	int		i;
	int		len;
	int		exist;
	char	**env;

	i = 0;
	exist = 0;
	env = *envp;
	if (!ft_strchr(str, '='))
		return (setenv_err(1));
	else if ((len = ft_strclen(str, '=')) == 0)
		return (setenv_err(2));
	while (env[i] && exist == 0)
	{
		if (ft_strncmp(str, env[i], len) == 0)
		{
			exist = 1;
			free(env[i]);
			env[i] = ft_strdup(str);
		}
		i++;
	}
	if (!exist)
		*envp = ft_tab_insert(str, envp);
	return (1);
}

int			ft_lst_setenv(char **argv, char ***envp)
{
	int		i;

	i = 1;
	while (argv[i])
	{
		if (ft_setenv(argv[i], envp) == 0)
			return (0);
		i++;
	}
	return (0);
}
