/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 12:29:17 by clanglai          #+#    #+#             */
/*   Updated: 2018/02/18 15:02:23 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# define BUFF_SIZE 8

typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

int						get_next_line(const int fd, char **line);
char					*ft_putadress(void *adr, char *str);
int						ft_tounicode(wchar_t c, int i);
int						ft_strnchr(char *s, int c);
int						ft_issign(char c);
int						ft_atoi(const char *str);
int						ft_tolower(int c);
int						ft_toupper(int c);
size_t					ft_strlen(const char *s);
char					*ft_strndup(const char *s1, int i);
char					*ft_strdup(const char *s1);
char					*ft_strcpy(char *dst, const char *src);
char					*ft_strncpy(char *dst, const char *src, size_t len);
char					*ft_strcat(char *s1, const char *s2);
char					*ft_strncat(char *s1, const char *s2, size_t n);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
char					*ft_strstr(const char *haystack, const char *needle);
char					*ft_strnstr(const char *haystack, const char *needle,
size_t len);
void					ft_sort_int_tab(int *tab, int len);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isprint(int c);
int						ft_isascii(int c);
void					*ft_memset(void *b, int c, size_t len);
void					ft_bzero(void *s, size_t n);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					*ft_memccpy(void *dst, const void *src, int c,
						size_t n);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
void					*ft_memalloc(size_t size);
void					ft_memdel(void **ap);
char					*ft_strnew(size_t size);
void					ft_strdel(char **as);
void					ft_strclr(char *s);
void					ft_striter(char *s, void(*f)(char*));
void					ft_striteri(char *s, void(*f)(unsigned int, char*));
char					*ft_strmap(char const *s, char(*f)(char));
char					*ft_strmapi(char const *s, char(*f)(unsigned int,
char));
int						ft_strequ(char const *s1, char const *s2);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
char					*ft_strsub(char const *s, unsigned int start,
size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strtrim(char const *s);
char					**ft_strsplit(char const *s, char c);
char					*ft_itoa(int n);
char					*ft_uitoa(int n);
char					*ft_itoa_long(long int n);
char					*ft_itoa_long_long(long long int n);
char					*ft_itoa_size_t(ssize_t n);
char					*ft_uitoa_size_t(size_t n);
char					*ft_itoa_intmax_t(intmax_t n);
char					*ft_ulitoa(unsigned long int n);
char					*ft_ullitoa(unsigned long long int n);
char					*ft_umaxitoa(uintmax_t n);
char					*ft_itoa_proper_base(unsigned int nb, char *str);
char					*ft_ulitoa_proper_base(unsigned long int nb, char *str);
char					*ft_ullitoa_proper_base(unsigned long long int nb,
char *str);
char					*ft_umaxitoa_proper_base(uintmax_t nb, char *str);
char					*ft_stitoa_proper_base(size_t nb, char *str);
int						ft_putstr_size(char const *s);
void					ft_putchar(char c);
void					ft_putchar_print(char c);
void					ft_putstr(char const *s);
void					ft_putendl(char const *s);
void					ft_putnbr(int n);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr_fd(int n, int fd);
t_list					*ft_lstnew(void const *content, size_t content_size);
void					ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list*(*f)(t_list *elem));
char					*ft_swap(char *s);
char					*ft_strnew_fill(size_t size, char c);
int						ft_find_max_tab(int *tab);
int						ft_find_min_tab(int *tab);
#endif
