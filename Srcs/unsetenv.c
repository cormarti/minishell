/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 09:12:54 by cormarti          #+#    #+#             */
/*   Updated: 2018/03/21 13:50:55 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

char		**rm_tabindex(int index, char ***tab)
{
	char	**tmp;
	char	**copy;
	int		i;
	int		j;

	i = 0;
	j = 0;
	copy = *tab;
	tmp = ft_tabledup(copy);
	while (copy[i])
		i++;
	free_arr(copy);
	if (!(copy = (char**)malloc(sizeof(char*) * i)))
		return (NULL);
	copy[i <= 0 ? 0 : i - 1] = NULL;
	i = 0;
	while (tmp[i])
	{
		if (i != index)
			copy[j++] = ft_strdup(tmp[i]);
		i++;
	}
	*tab = copy;
	free_arr(tmp);
	return (*tab);
}

static void	ft_unsetenv(char *name, char ***envp)
{
	char	**env;
	int		i;
	int		len;

	name = ft_strjoin(name, "=");
	len = ft_strlen(name);
	env = *envp;
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], name, len) == 0)
		{
			*envp = rm_tabindex(i, envp);
			break ;
		}
		i++;
	}
	free(name);
}

void		ft_lst_unsetenv(char **argv, char ***envp)
{
	int		i;

	i = 0;
	while (argv[i])
	{
		ft_unsetenv(argv[i], envp);
		i++;
	}
}
