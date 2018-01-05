/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:21:41 by clanglai          #+#    #+#             */
/*   Updated: 2017/12/14 13:26:55 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew_fill(size_t size, char c)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!(str = malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (i < size)
	{
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	return (str);
}
