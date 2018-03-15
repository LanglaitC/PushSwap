/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:08:03 by clanglai          #+#    #+#             */
/*   Updated: 2018/03/15 12:48:23 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../inc/libft.h"

static int	ft_count_words(const char *s, char c)
{
	int	i;
	int	word;
	int state;

	i = 0;
	word = 0;
	state = 1;
	while (s[i])
	{
		if (s[i] == c)
			state = 1;
		else
		{
			if (state == 1)
				word++;
			state = 0;
		}
		i++;
	}
	return (word);
}

static char	*ft_get_words(char **str, char c)
{
	int		i;
	int		j;
	char	*cpy;

	i = 0;
	j = 0;
	while ((**str == c && **str))
		*str = *str + 1;
	while ((*str)[i] != c && (*str)[i])
		i++;
	if (!(cpy = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (j < i)
	{
		cpy[j] = **str;
		*str = *str + 1;
		j++;
	}
	cpy[j] = '\0';
	return (cpy);
}

char		**ft_strsplit(char const *s, char c)
{
	char	*cpy;
	int		words;
	char	**tab;
	int		i;

	i = 0;
	words = ft_count_words(s, c);
	cpy = (char*)s;
	if (!(tab = (char**)malloc(sizeof(char*) * (words + 1))))
		return (NULL);
	while (i < words)
	{
		tab[i] = ft_get_words(&cpy, c);
		i++;
	}
	tab[i] = 0;
	return (tab);
}
