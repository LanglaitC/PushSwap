/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_signs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 13:23:34 by clanglai          #+#    #+#             */
/*   Updated: 2018/01/05 10:46:10 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

char	*ft_swap_signs(t_config *config, char *str, int state, int i)
{
	char	c;

	if ((str[0] != '\0' && config->flag[2] == 0) || config->spec == 'p')
	{
		if ((i = ft_strnchr(str, '+')) != -1)
			state = 1;
		else if ((i = ft_strnchr(str, '-')) != -1)
			state = 1;
		else if ((i = ft_strnchr(str, 'x')) != -1)
			state = 1;
		else if ((i = ft_strnchr(str, 'X')) != -1)
			state = 1;
		else if ((i = ft_strnchr(str, ' ')) != -1)
			state = 1;
		if (state == 1)
		{
			c = str[i];
			str[i] = '0';
			if (c == '-' || c == '+' || c == ' ')
				str[ft_strnchr(str, '0')] = c;
			else
				str[ft_strnchr(str, '0') + 1] = c;
		}
	}
	return (str);
}

int		ft_handle_unicode(wchar_t c, int *k, t_config *config)
{
	if (c > 0 && c < 129)
	{
		if (*k + 1 <= config->prec || config->prec == -1)
			*k = *k + 1;
		else
			return (0);
	}
	else if (c > 128 && c < 2048)
	{
		if (*k + 2 <= config->prec || config->prec == -1)
			*k = *k + 2;
		else
			return (0);
	}
	else if (c > 2047 && c < 65536)
	{
		if (*k + 3 <= config->prec || config->prec == -1)
			*k = *k + 3;
		else
			return (0);
	}
	return (1);
}

size_t	ft_lenx(char *str)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] == 'x' || str[i] == 'X')
			k = 0;
		k++;
		i++;
	}
	return (k);
}

void	ft_delconfig(t_config *config)
{
	if (config)
	{
		ft_memdel((void**)&config->flag);
		ft_memdel((void**)&config);
	}
}
