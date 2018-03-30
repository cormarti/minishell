/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 13:33:06 by cormarti          #+#    #+#             */
/*   Updated: 2018/03/21 06:57:33 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tab_insert(char *new, char ***tab)
{
	int		i;
	char	**tmp;
	char	**copy;

	i = 0;
	copy = *tab;
	tmp = ft_tabledup(copy);
	while (tmp[i])
		i++;
	free_arr(copy);
	if (!(copy = (char**)malloc(sizeof(char*) * (i + 2))))
		return (0);
	copy[i + 1] = NULL;
	i = 0;
	while (tmp[i])
	{
		copy[i] = ft_strdup(tmp[i]);
		i++;
	}
	copy[i] = ft_strdup(new);
	*tab = copy;
	free_arr(tmp);
	return (*tab);
}
