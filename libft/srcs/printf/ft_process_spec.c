/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_spec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 14:08:43 by clanglai          #+#    #+#             */
/*   Updated: 2017/12/20 16:41:57 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	ft_process_spec(t_config *config, va_list *args)
{
	int size;

	size = 0;
	if (ft_isvalid(config->spec) == 4)
		size = ft_process_int(config, args);
	else if (ft_isvalid(config->spec) == 5)
		size = ft_process_uns_int(config, args);
	else if (ft_isvalid(config->spec) == 6)
		size = ft_process_int2(config, args);
	else if (ft_isvalid(config->spec) == 7)
		size = ft_process_string(config, args);
	else if (ft_isvalid(config->spec) == 8)
		size = ft_process_void(config, args);
	else if (ft_isvalid(config->spec) == 9)
		return (ft_process_percent(config));
	if (size == -1)
		return (-1);
	return (size);
}

int	ft_process_int(t_config *config, va_list *args)
{
	if (config->spec == 'D')
		config->len = 2;
	if (config->len == 0)
		return (ft_int(config, va_arg(*args, int)));
	if (config->len == 5)
		return (ft_signed_char(config, va_arg(*args, signed int)));
	else if (config->len == 1)
		return (ft_short_int(config, va_arg(*args, int)));
	else if (config->len == 2)
		return (ft_long(config, va_arg(*args, long int)));
	else if (config->len == 6)
		return (ft_long_long(config, va_arg(*args, long long int)));
	else if (config->len == 3)
		return (ft_intmax_t(config, va_arg(*args, intmax_t)));
	else if (config->len == 4)
		return (ft_size_t(config, va_arg(*args, size_t)));
	return (0);
}

int	ft_process_uns_int(t_config *config, va_list *args)
{
	if (config->spec == 'O')
		config->len = 2;
	if (config->spec == 'U')
		config->len = 2;
	if (config->len == 0)
		return (ft_uns_int(config, va_arg(*args, unsigned int)));
	if (config->len == 5)
		return (ft_uns_char(config, va_arg(*args, unsigned int)));
	else if (config->len == 1)
		return (ft_uns_short(config, va_arg(*args, unsigned int)));
	else if (config->len == 2)
		return (ft_uns_long(config, va_arg(*args, unsigned long int)));
	else if (config->len == 6)
		return (ft_ulg_lg(config, va_arg(*args, unsigned long long int)));
	else if (config->len == 3)
		return (ft_uintmax_t(config, va_arg(*args, uintmax_t)));
	else if (config->len == 4)
		return (ft_size_t2(config, va_arg(*args, size_t)));
	return (0);
}

int	ft_process_string(t_config *config, va_list *args)
{
	if (config->spec == 'S')
		config->len = 2;
	if (config->len == 0)
		return (ft_string(config, va_arg(*args, int*)));
	if (config->len == 2)
		return (ft_wchar_t(config, va_arg(*args, wchar_t*), 0, 0));
	return (0);
}

int	ft_process_int2(t_config *config, va_list *args)
{
	if (config->spec == 'C')
		config->len = 2;
	if (config->len == 0)
		return (ft_int2(config, va_arg(*args, int)));
	if (config->len == 2)
		return (ft_wint_t(config, va_arg(*args, wint_t)));
	return (0);
}
