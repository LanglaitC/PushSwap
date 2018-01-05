/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_int3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 10:15:06 by clanglai          #+#    #+#             */
/*   Updated: 2018/01/04 19:47:58 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	ft_ulg_lg(t_config *config, unsigned long long int number)
{
	char	*str;

	if (config->spec == 'u' || config->spec == 'U')
		if (!(str = ft_ullitoa(number)))
			return (-1);
	if (config->spec == 'o' || config->spec == 'O')
		if (!(str = ft_ullitoa_proper_base(number, "01234567")))
			return (-1);
	if (config->spec == 'x')
		if (!(str = ft_ullitoa_proper_base(number, "0123456789abcdef")))
			return (-1);
	if (config->spec == 'X')
		if (!(str = ft_ullitoa_proper_base(number, "0123456789ABCDEF")))
			return (-1);
	if (!(str = ft_handle_flag(config, str)))
		return (-1);
	return (ft_putstr_size(str));
}

int	ft_uintmax_t(t_config *config, uintmax_t number)
{
	char		*str;

	if (config->spec == 'u' || config->spec == 'U')
		if (!(str = ft_umaxitoa(number)))
			return (-1);
	if (config->spec == 'o' || config->spec == 'O')
		if (!(str = ft_umaxitoa_proper_base(number, "01234567")))
			return (-1);
	if (config->spec == 'x')
		if (!(str = ft_umaxitoa_proper_base(number, "0123456789abcdef")))
			return (-1);
	if (config->spec == 'X')
		if (!(str = ft_umaxitoa_proper_base(number, "0123456789ABCDEF")))
			return (-1);
	if (!(str = ft_handle_flag(config, str)))
		return (-1);
	return (ft_putstr_size(str));
}

int	ft_size_t2(t_config *config, size_t number)
{
	char	*str;

	if (config->spec == 'u' || config->spec == 'U')
		if (!(str = ft_uitoa_size_t(number)))
			return (-1);
	if (config->spec == 'o' || config->spec == 'O')
		if (!(str = ft_stitoa_proper_base(number, "01234567")))
			return (-1);
	if (config->spec == 'x')
		if (!(str = ft_stitoa_proper_base(number, "0123456789abcdef")))
			return (-1);
	if (config->spec == 'X')
		if (!(str = ft_stitoa_proper_base(number, "0123456789ABCDEF")))
			return (-1);
	if (!(str = ft_handle_flag(config, str)))
		return (-1);
	return (ft_putstr_size(str));
}

int	ft_int2(t_config *config, int number)
{
	char *tmp;

	if (config->width)
		config->width--;
	if (!(tmp = ft_strnew(1)))
		return (-1);
	if (!(tmp = ft_handle_flag(config, tmp)))
		return (-1);
	if (config->flag[2] != 1)
	{
		ft_putstr(tmp);
		ft_putchar((char)number);
	}
	else
	{
		ft_putchar((char)number);
		ft_putstr(tmp);
	}
	return (ft_strlen(tmp) + 1);
}

int	ft_wint_t(t_config *config, wint_t number)
{
	char	*tmp;
	int		j;
	int		i;

	if (config->width)
		config->width -= ft_unicode_value(number);
	if (!(tmp = ft_strnew(1)))
		return (-1);
	if (!(tmp = ft_handle_flag(config, tmp)))
		return (-1);
	if (config->flag[2] != 1)
	{
		ft_putstr(tmp);
		j = ft_tounicode((wchar_t)number, 4);
	}
	else
	{
		j = ft_tounicode((wchar_t)number, 4);
		ft_putstr(tmp);
	}
	i = ft_strlen(tmp);
	ft_memdel((void**)&tmp);
	return (i + j);
}
