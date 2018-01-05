/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_int2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 10:11:13 by clanglai          #+#    #+#             */
/*   Updated: 2017/12/20 15:14:12 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	ft_intmax_t(t_config *config, intmax_t number)
{
	char	*str;

	if (!(str = ft_itoa_intmax_t(number)))
		return (-1);
	if (!str)
		return (0);
	if (!(str = ft_handle_flag(config, str)))
		return (-1);
	return (ft_putstr_size(str));
}

int	ft_size_t(t_config *config, size_t number)
{
	char	*str;

	if (!(str = ft_itoa_size_t(number)))
		return (-1);
	if (!str)
		return (0);
	if (!(str = ft_handle_flag(config, str)))
		return (-1);
	return (ft_putstr_size(str));
}

int	ft_uns_int(t_config *config, unsigned int number)
{
	char *str;

	if (config->spec == 'u' || config->spec == 'U')
		if (!(str = ft_uitoa(number)))
			return (-1);
	if (config->spec == 'o' || config->spec == 'O')
		if (!(str = ft_itoa_proper_base(number, "01234567")))
			return (-1);
	if (config->spec == 'x')
		if (!(str = ft_itoa_proper_base(number, "0123456789abcdef")))
			return (-1);
	if (config->spec == 'X')
		if (!(str = ft_itoa_proper_base(number, "0123456789ABCDEF")))
			return (-1);
	if (!(str = ft_handle_flag(config, str)))
		return (-1);
	return (ft_putstr_size(str));
}

int	ft_uns_short(t_config *config, unsigned int number)
{
	char				*str;
	unsigned short int	nbr;

	nbr = number;
	if (config->spec == 'u' || config->spec == 'U')
		if (!(str = ft_uitoa(nbr)))
			return (-1);
	if (config->spec == 'o' || config->spec == 'O')
		if (!(str = ft_itoa_proper_base(nbr, "01234567")))
			return (-1);
	if (config->spec == 'x')
		if (!(str = ft_itoa_proper_base(nbr, "0123456789abcdef")))
			return (-1);
	if (config->spec == 'X')
		if (!(str = ft_itoa_proper_base(nbr, "0123456789ABCDEF")))
			return (-1);
	if (!(str = ft_handle_flag(config, str)))
		return (-1);
	return (ft_putstr_size(str));
}

int	ft_uns_long(t_config *config, unsigned long int number)
{
	char	*str;

	if (config->spec == 'u' || config->spec == 'U')
		if (!(str = ft_ulitoa(number)))
			return (-1);
	if (config->spec == 'o' || config->spec == 'O')
		if (!(str = ft_ulitoa_proper_base(number, "01234567")))
			return (-1);
	if (config->spec == 'x')
		if (!(str = ft_ulitoa_proper_base(number, "0123456789abcdef")))
			return (-1);
	if (config->spec == 'X')
		if (!(str = ft_ulitoa_proper_base(number, "0123456789ABCDEF")))
			return (-1);
	if (!(str = ft_handle_flag(config, str)))
		return (-1);
	return (ft_putstr_size(str));
}
