/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:47:28 by clanglai          #+#    #+#             */
/*   Updated: 2017/11/10 12:43:50 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i])
	{
		if ((unsigned const char)s1[i] != (unsigned const char)s2[i])
			return ((unsigned const char)s1[i] - (unsigned const char)s2[i]);
		i++;
	}
	return ((unsigned const char)s1[i] - (unsigned const char)s2[i]);
}
