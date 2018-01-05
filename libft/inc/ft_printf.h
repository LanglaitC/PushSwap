/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:09:33 by clanglai          #+#    #+#             */
/*   Updated: 2018/01/05 12:55:57 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include <wchar.h>

typedef struct	s_config
{
	int		*flag;
	int		prec;
	int		width;
	int		len;
	char	spec;
	int		size;

}				t_config;

void			ft_delconfig(t_config *config);
size_t			ft_lenx(char *str);
int				ft_handle_unicode(wchar_t c, int *k, t_config *config);
char			*ft_handle_prec_adr(t_config *config, char *str, int len);
char			*ft_handle_prec_int(t_config *config, char *str, int len);
int				ft_process_invalid(const char *str, int *i, char c);
int				ft_printf(const char *format, ...);
int				ft_isvalid(char c);
t_config		*ft_getstruct(const char *s, int i);
int				ft_isflag(char c);
int				ft_process_percent(t_config *config);
int				ft_islength(char c);
int				ft_process_spec(t_config *config, va_list *arg);
int				ft_process_int(t_config *config, va_list *arg);
int				ft_process_uns_int(t_config *config, va_list *arg);
int				ft_process_int2(t_config *config, va_list *arg);
int				ft_process_string(t_config *config, va_list *arg);
int				ft_process_void(t_config *config, va_list *arg);
int				ft_int(t_config *config, int number);
int				ft_signed_char(t_config *config, signed number);
int				ft_short_int(t_config *config, int number);
int				ft_long(t_config *config, long int number);
int				ft_long_long(t_config *config, long long int number);
int				ft_intmax_t(t_config *config, intmax_t number);
int				ft_size_t(t_config *config, size_t number);
int				ft_uns_int(t_config *config, unsigned int number);
int				ft_uns_char(t_config *config, unsigned int letter);
int				ft_uns_short(t_config *config, unsigned int number);
int				ft_uns_long(t_config *config, unsigned long int number);
int				ft_ulg_lg(t_config *config, unsigned long long int number);
int				ft_uintmax_t(t_config *config, uintmax_t number);
int				ft_size_t2(t_config *config, size_t number);
int				ft_int2(t_config *config, int number);
int				ft_wint_t(t_config *config, wint_t number);
int				ft_string(t_config *config, int *str);
int				ft_wchar_t(t_config *config, wchar_t *str, int i, int j);
char			*ft_handle_flag(t_config *config, char *str);
char			*ft_swap_signs(t_config *config, char *str, int state, int i);
int				ft_unicode_value(wint_t c);
#endif
