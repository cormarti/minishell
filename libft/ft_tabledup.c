/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabledup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 13:18:40 by cormarti          #+#    #+#             */
/*   Updated: 2018/03/15 13:29:10 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabledup(char **tab)
{
	char	**dest;
	int		len;

	len = 0;
	while (tab[len])
		len++;
	if (!(dest = (char**)malloc(sizeof(char*) * (len + 1))))
		return (NULL);
	dest[len] = NULL;
	len = 0;
	while (tab[len])
	{
		dest[len] = ft_strdup(tab[len]);
		len++;
	}
	return (dest);
}
