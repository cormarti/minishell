/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 17:41:25 by cormarti          #+#    #+#             */
/*   Updated: 2018/02/07 17:41:27 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strclen(char *str, int c)
{
	int				len;

	len = 0;
	while (str[len] && (str[len] != (unsigned char)c))
		len++;
	return (len);
}
