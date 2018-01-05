/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 10:18:52 by clanglai          #+#    #+#             */
/*   Updated: 2018/01/05 12:23:47 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int			ft_signed_char(t_config *config, signed int letter)
{
	char		*str;
	signed char	c;

	c = letter;
	if (!(str = ft_itoa(c)))
		return (-1);
	if (!str)
		return (0);
	if (!(str = ft_handle_flag(config, str)))
		return (-1);
	return (ft_putstr_size(str));
}

int			ft_uns_char(t_config *config, unsigned int letter)
{
	char			*str;
	unsigned char	c;

	c = letter;
	if (config->spec == 'u' || config->spec == 'U')
		if (!(str = ft_uitoa(c)))
			return (-1);
	if (config->spec == 'o' || config->spec == 'O')
		if (!(str = ft_itoa_proper_base(c, "01234567")))
			return (-1);
	if (config->spec == 'x')
		if (!(str = ft_itoa_proper_base(c, "0123456789abcdef")))
			return (-1);
	if (config->spec == 'X')
		if (!(str = ft_itoa_proper_base(c, "0123456789ABCDEF")))
			return (-1);
	if (!(str = ft_handle_flag(config, str)))
		return (-1);
	return (ft_putstr_size(str));
}

int			ft_string(t_config *config, int *str)
{
	char *tmp;
	char *cpy;

	if (str != NULL)
	{
		if (!(cpy = ft_strdup((char*)str)))
			return (-1);
		if (!(tmp = ft_handle_flag(config, cpy)))
			return (-1);
	}
	else
	{
		if (!(cpy = ft_strdup("(null)")))
			return (-1);
		if (!(tmp = ft_handle_flag(config, cpy)))
			return (-1);
	}
	return (ft_putstr_size(tmp));
}

static int	ft_writespaces(int j, wchar_t *str, t_config *config, char c)
{
	int i;
	int k;
	int state;

	c = (config->flag[3] == 1) ? '0' : ' ';
	state = 1;
	i = -1;
	k = 0;
	if (config->flag[2] == 1 && j == 0)
		return (0);
	if (config->flag[2] == 0 && j != 0)
		return (0);
	while (str[++i] && state == 1)
		state = (ft_handle_unicode(str[i], &k, config));
	i = -1;
	while (++i < config->width - k)
		write(1, &c, 1);
	return (i);
}

int			ft_wchar_t(t_config *config, wchar_t *str, int i, int j)
{
	char	*tmp;
	int		res;

	res = 0;
	if (str == NULL)
	{
		if (!(tmp = ft_strdup("(null)")))
			return (-1);
		if (!(tmp = ft_handle_flag(config, tmp)))
			return (-1);
		return (ft_putstr_size(tmp));
	}
	else
	{
		res += ft_writespaces(0, str, config, ' ');
		while (str[i] != '\0' && (j < config->prec || config->prec == -1))
		{
			if ((j += ft_tounicode(str[i], ((config->prec == -1) ?
								-1 : config->prec - j))) < 0)
				return (-1);
			i++;
		}
		res += ft_writespaces(1, str, config, ' ');
	}
	return (res + j);
}
