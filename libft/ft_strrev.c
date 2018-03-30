/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 23:21:04 by cormarti          #+#    #+#             */
/*   Updated: 2018/03/10 04:39:50 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	char	tmp;
	int		i;
	int		str_len;

	str_len = 0;
	i = 0;
	while (str[str_len] != '\0')
	{
		str_len++;
	}
	while (i < (str_len / 2))
	{
		tmp = str[i];
		str[i] = str[str_len - i - 1];
		str[str_len - i - 1] = tmp;
		i++;
	}
	return (str);
}
