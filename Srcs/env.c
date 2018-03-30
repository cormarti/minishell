/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 05:12:13 by cormarti          #+#    #+#             */
/*   Updated: 2018/03/21 07:58:12 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

static void	print_env(char **envp)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		ft_putendl(envp[i]);
		i++;
	}
}

void		ft_env(char **argv, char **envp)
{
	int		cmd;
	char	**env;

	env = ft_tabledup(envp);
	cmd = 0;
	argv++;
	while (argv[0] && !cmd)
	{
		if (ft_strchr(argv[0], '='))
		{
			ft_setenv(argv[0], &env);
			argv++;
		}
		else
		{
			cmd = 1;
			sys_cmd(argv, env);
		}
	}
	if (!cmd)
		print_env(env);
	free_arr(env);
}
