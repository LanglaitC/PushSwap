/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:43:36 by clanglai          #+#    #+#             */
/*   Updated: 2018/03/16 15:13:43 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include <stdlib.h>

char		*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*cpy;

	i = ft_strlen(s1);
	if (!(cpy = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	j = 0;
	while (j < i)
	{
		cpy[j] = s1[j];
		j++;
	}
	cpy[j] = '\0';
	return (cpy);
}
