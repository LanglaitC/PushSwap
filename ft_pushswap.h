/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 15:39:07 by clanglai          #+#    #+#             */
/*   Updated: 2018/02/15 10:49:36 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP_H
# define FT_PUSHSWAP_H

#include "libft/inc/libft.h"
#include "libft/inc/ft_printf.h"

typedef	struct		s_pile
{
	int				content;
	struct s_pile	*next;
	int				sort;
}					t_pile;

void				ft_sort_pile(t_pile **pile, t_pile **pb);
int					ft_create_a_pile(t_pile **start, int argc, char **argv);
t_pile				*ft_lstnewpile(int i);
int					ft_check_int(char *str);
int					ft_execute_actions(t_pile **pile_a, int argc, char **argv);
void				ft_sa(t_pile *pa);
void				ft_sb(t_pile *pb);
void				ft_ss(t_pile *pa, t_pile *pb);
void				ft_pa(t_pile **pa, t_pile **pb);
void				ft_pb(t_pile **pa, t_pile **pb);
void				ft_ra(t_pile *pa);
void				ft_rb(t_pile *pb);
void				ft_rr(t_pile *pa, t_pile *pb);
void				ft_rra(t_pile *pa);
void				ft_rrb(t_pile *pb);
int					ft_find_max(t_pile **pa, int s);
int					ft_check_sort(t_pile **pa, t_pile **pb);
int					ft_check_double_input(t_pile **pa, int number);
int					ft_find_max(t_pile **pa, int s);
int					ft_find_min(t_pile **pa, int s);
int					ft_find_index(t_pile **pa, int x);
int					ft_find_med(t_pile **pa, int len, int sort);
int					ft_find_ele_x(t_pile **pa, int x);
int					ft_count_elem(t_pile **pa, int s);
int					ft_create_a_pile_arg(t_pile **start, int argc, char **argv);
void				ft_add_at_end(t_pile **st, int ac, t_pile **pa, t_pile**pb);
void				ft_print_res(t_pile **res);
int					ft_count_sorted(t_pile **pile);
int					ft_count_inv_sorted(t_pile **pile);
int					ft_is_next(t_pile **pa);
void				ft_attribute_sort(t_pile ** pb, int sort);
int					ft_find_value_below(t_pile **pa, int x, int s);
#endif
