/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 23:39:59 by cormarti          #+#    #+#             */
/*   Updated: 2018/03/22 23:55:07 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"
#include "../Includes/ext.h"

int			sys_fork(char *path, char **argv, char **envp)
{
	int		status;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		ft_putstr("error: failed to fork\n");
	else if (pid > 0)
		waitpid(pid, &status, 0);
	else
	{
		execve(path, argv, envp);
		exit(0);
	}
	return (1);
}

static int	check_builtin(char **argv, char ***envp)
{
	int		i;

	i = 0;
	if (!argv[0])
		exit(0);
	while (g_builtin[i])
	{
		if (ft_strcmp(g_builtin[i], argv[0]) == 0)
		{
			call_builtin(argv, envp);
			return (1);
		}
		i++;
	}
	return (0);
}

int			main(int argc, char **argv, char **envp)
{
	char		*line;
	char		**envi;
	int			i;
	char		**arg;

	i = 0;
	if (argc != 1 && argv)
		exit(0);
	envi = ft_tabledup(envp);
	print_currpath();
	while (42)
	{
		if (get_next_line(0, &line) == 1)
		{
			if (line && line[0] != '\0'
				&& (arg = ft_split_whitespaces(line)) != NULL)
			{
				if (arg[0] && check_builtin(arg, &envi) == 0)
					sys_cmd(arg, envi);
				free_arr(arg);
			}
			print_currpath();
		}
		free(line);
	}
}
