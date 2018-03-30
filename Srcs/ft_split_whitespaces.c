/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 11:06:57 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/22 22:39:07 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

static void	init(int *i, int *j, int *k)
{
	*i = -1;
	*j = -1;
	*k = -1;
}

static int	is_delimiter(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r')
		return (1);
	return (0);
}

static int	nb_words(char *str)
{
	int		i;
	int		nb_words;

	i = 0;
	nb_words = 0;
	while (str[i])
	{
		if (!is_delimiter(str[i]))
			if (i == 0 || (i > 0 && is_delimiter(str[i - 1])))
				nb_words++;
		i++;
	}
	return (nb_words);
}

char		**ft_split_whitespaces(char *str)
{
	char	**dest;
	int		i;
	int		j;
	int		k;

	init(&i, &j, &k);
	i = ft_strlen(str);
	if (!(dest = (char**)malloc(sizeof(char*) * (nb_words(str) + 1))))
		return (NULL);
	dest[nb_words(str)] = NULL;
	while (++j < (nb_words(str)))
		dest[j] = ft_strnew(i);
	init(&i, &j, &k);
	while (str[++i] && j < nb_words(str))
		if (!is_delimiter(str[i]))
		{
			if (i == 0 || (i > 0 && is_delimiter(str[i - 1])))
			{
				k = -1;
				j++;
			}
			dest[j][++k] = str[i];
			dest[j][k + 1] = 0;
		}
	return (dest);
}
