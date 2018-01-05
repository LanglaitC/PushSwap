/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:08:03 by clanglai          #+#    #+#             */
/*   Updated: 2017/11/13 12:07:54 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

static char	*ft_create_word(char *s, char c)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	if (!(str = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*ft_advance_pointer(char *s, char c)
{
	while (*s != c)
		s++;
	while (*s == c)
		s++;
	return (s);
}

static char	**ft_create_table(char **tab, int words, char *s, char c)
{
	int i;

	i = 0;
	if (s[0] == c)
		s = ft_advance_pointer(s, c);
	while (i < words)
	{
		tab[i] = ft_create_word(s, c);
		s = ft_advance_pointer(s, c);
		i++;
	}
	tab[i] = 0;
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	int		words;
	char	**tab;
	char	*cpy;

	if (!s)
		return (0);
	cpy = (char*)s;
	words = ft_count_words(s, c);
	if (!(tab = (char**)malloc(sizeof(char*) * (words + 1))))
		return (NULL);
	tab = ft_create_table(tab, words, cpy, c);
	return (tab);
}
