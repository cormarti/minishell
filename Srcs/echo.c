/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 09:10:34 by cormarti          #+#    #+#             */
/*   Updated: 2018/03/19 17:55:48 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

void	ft_echo(char **argv)
{
	int		i;

	i = 1;
	while (argv[i])
	{
		ft_putstr(argv[i]);
		if (argv[i + 1])
			ft_putstr(" ");
		i++;
	}
	ft_putstr("\n");
}