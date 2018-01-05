/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 13:20:02 by clanglai          #+#    #+#             */
/*   Updated: 2018/01/05 12:29:12 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static char	*ft_handle_plus_space(t_config *config, char *str)
{
	char *tmp;

	if ((ft_isdigit(str[0]) && ft_strnchr(str, '+') == -1 && ft_strnchr(str,
					'-') == -1) || config->prec == 0)
	{
		if (config->flag[1] == 1)
		{
			if (!(tmp = ft_strjoin("+", str)))
				return (NULL);
		}
		else
		{
			if (!(tmp = ft_strjoin(" ", str)))
				return (NULL);
		}
		ft_memdel((void**)&str);
		return (tmp);
	}
	return (str);
}

static char	*ft_handle_hashtag(t_config *config, char *str)
{
	char *tmp;

	if (str[0] == '0')
		return (str);
	if (config->spec == 'o' || config->spec == 'O')
	{
		if (!(tmp = ft_strjoin("0", str)))
			return (NULL);
	}
	else if (config->spec == 'x')
	{
		if (!(tmp = ft_strjoin("0x", str)))
			return (NULL);
	}
	else if (config->spec == 'X')
	{
		if (!(tmp = ft_strjoin("0X", str)))
			return (NULL);
	}
	else
		return (str);
	ft_memdel((void**)&str);
	return (tmp);
}

static char	*ft_handle_width(t_config *config, char *str, int len, char *tmp)
{
	char *spaces;

	if (len >= config->width)
		return (str);
	if (config->flag[3] == 1)
	{
		if (!(spaces = ft_strnew_fill(config->width - len, '0')))
			return (NULL);
	}
	if (config->flag[3] == 0)
	{
		if (!(spaces = ft_strnew_fill(config->width - len, ' ')))
			return (NULL);
	}
	if (config->flag[2] == 1)
	{
		if (!(tmp = ft_strjoin(str, spaces)))
			return (NULL);
	}
	if (config->flag[2] == 0)
		if (!(tmp = ft_strjoin(spaces, str)))
			return (NULL);
	free(spaces);
	free(str);
	return (tmp);
}

static char	*ft_handle_prec(t_config *config, char *str, int len)
{
	char	*tmp;

	tmp = NULL;
	if (ft_isvalid(config->spec) == 4 || ft_isvalid(config->spec) == 5)
		return (ft_handle_prec_int(config, str, len));
	else if (ft_isvalid(config->spec) == 7)
	{
		if ((int)ft_strlen(str) < config->prec)
			return (str);
		if (!(tmp = ft_strsub(str, 0, config->prec)))
			return (NULL);
	}
	else if (ft_isvalid(config->spec) == 8)
		return (ft_handle_prec_adr(config, str, len));
	ft_memdel((void**)&str);
	return (tmp);
}

char		*ft_handle_flag(t_config *config, char *str)
{
	char	*tmp;
	int		spec;

	spec = ft_isvalid(config->spec);
	if (!(tmp = ft_strdup(str)))
		return (NULL);
	if (spec == 5 && (config->flag[4]))
		if (!(tmp = ft_handle_hashtag(config, tmp)))
			return (NULL);
	if (config->prec >= 0 && (spec == 4 || spec == 5 || spec == 7 || spec == 8))
		if (!(tmp = ft_handle_prec(config, tmp, ft_strlen(tmp) + 1)))
			return (NULL);
	if (spec == 4 && (config->flag[1] || config->flag[0]))
		if (!(tmp = ft_handle_plus_space(config, tmp)))
			return (NULL);
	if (tmp == NULL && config->width)
		if (!(tmp = ft_handle_width(config, tmp, 0, NULL)))
			return (NULL);
	if (tmp != NULL && config->width)
		if (!(tmp = ft_handle_width(config, tmp, ft_strlen(tmp), NULL)))
			return (NULL);
	if (spec == 4 || spec == 5 || spec == 8)
		tmp = ft_swap_signs(config, tmp, 0, 0);
	ft_memdel((void**)&str);
	return (tmp);
}
