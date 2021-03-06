/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 15:39:07 by clanglai          #+#    #+#             */
/*   Updated: 2018/03/20 16:23:23 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP_H
# define FT_PUSHSWAP_H

# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"
# include "../minilibx/mlx.h"

# define T_WIDTH 800
# define T_HEIGHT 1300
# define LIM 1000

typedef	struct		s_pile
{
	int				content;
	struct s_pile	*next;
	int				sort;
}					t_pile;

typedef struct		s_insert
{
	int				content;
	int				found;
}					t_insert;

typedef struct		s_win
{
	t_pile	*pa;
	t_pile	*pb;
	t_list	*acts;
	void	*mlx;
	void	*win;
	void	*img;
	char	*str;
	int		nb_ele;
	int		bpp;
	int		s_p;
	int		end;
	int		*tab;
	int		c_flag;
	int		size_l;
}					t_win;

void				ft_sort_pile(t_pile **pile, t_pile **pb);
int					ft_create_a_pile(t_win *win, int argc, char **argv);
t_pile				*ft_lstnewpile(int i);
int					ft_check_int(char *str);
int					ft_execute_actions(t_win *win);
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
int					ft_check_single_sort(t_pile **pa, int sort);
int					ft_check_single_inv_sort(t_pile **pa, int sort);
int					ft_find_min(t_pile **pa, int s);
int					ft_find_index(t_pile **pa, int x);
int					ft_find_med(t_pile **pa, int len, int sort);
int					ft_find_last_three(t_pile **pa, int len, int sort);
int					ft_find_ele_x(t_pile **pa, int x);
int					ft_find_sort_x(t_pile **pa, int x);
int					ft_count_elem(t_pile **pa, int s);
int					ft_create_a_pile_arg(t_win *wim, char **argv);
void				ft_add_at_end(t_pile **st, int ac, t_pile **pa, t_pile**pb);
void				ft_print_res(t_pile **res);
int					ft_count_sorted(t_pile **pile);
int					ft_count_inv_sorted(t_pile **pile);
int					ft_is_next(t_pile **pa);
void				ft_attribute_sort(t_pile **pb, int sort, int state);
int					ft_find_value_below(t_pile **pa, int x, int s);
void				ft_choose_actions(t_pile **pa, t_pile **pb, char *line);
int					ft_check_single_inv_sort(t_pile **pb, int s);
int					ft_find_value_above(t_pile **pa, int x, int s);
int					ft_find_min_index(t_pile **pb, t_insert *max, int len);
void				ft_print_state(t_pile **pa, t_pile **pb);
void				ft_sort_pile_b_less_than_3(t_pile **pa, t_pile **pb,
		t_pile **res, int s);
void				ft_sort_pile_a_less_than_3(t_pile **pa, t_pile **pb,
		t_pile **res, int s);
void				ft_print_state(t_pile **pa, t_pile **pb);
void				ft_free(t_pile **pile);
void				ft_initialize_window(t_win *win, t_pile *pa);
void				ft_print_graph(t_pile *pb, t_pile *pa, t_win *win);
int					ft_handle_keypressing(t_win *win);
int					ft_tab_index(int *tab, int val, int len);
int					ft_handle_keys(int keycode, t_win *win);
void				ft_exec_all(t_win *win);
#endif
