/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:13:24 by clanglai          #+#    #+#             */
/*   Updated: 2018/01/05 12:31:26 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static int	ft_real_printf(const char *format, va_list *args, int i, int size)
{
	int			state;
	t_config	*config;

	while (format[i])
	{
		if (format[i] == '%' && (state = 1))
		{
			while (ft_isvalid(format[++i]) && state != 0)
				if (ft_isvalid(format[i]) > 3 && ft_isvalid(format[i]) <= 10)
				{
					if (!(config = ft_getstruct(format, i)))
						return (-1);
					if ((state = ft_process_spec(config, args)) < 0)
						return (-1);
					size += (state - config->size);
					state = 0;
					ft_delconfig(config);
				}
			size += state == 1 ? ft_process_invalid(format, &i, ' ') : 0;
		}
		if (format[i] && format[i] != '%')
			write(1, &format[i++], 1);
	}
	return (i + size);
}

int			ft_printf(const char *format, ...)
{
	int		res;
	va_list	args;

	va_start(args, format);
	res = ft_real_printf(format, &args, 0, 0);
	va_end(args);
	return (res);
}
