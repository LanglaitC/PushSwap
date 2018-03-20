# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clanglai <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/06 10:08:13 by clanglai          #+#    #+#              #
#    Updated: 2018/03/20 15:26:27 by clanglai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc

FLAG=-Wall -Wextra -Werror

NAME=libftprintf.a

SRC_PATH= srcs
INC_PATH= inc
LIB_PATH= lib
OBJ_PATH= obj
PRINTF_PATH= printf

INC_FILES=	ft_printf.h \
		libft.h

SRC_PRINTF= 	ft_checkflags.c \
		ft_config.c \
		ft_handle_flags.c \
		ft_printf.c \
		ft_process_char.c \
		ft_process_int.c \
		ft_process_int2.c \
		ft_process_int3.c \
		ft_process_spec.c \
		ft_process_void.c \
		ft_swap_signs.c \
		ft_handle_prec.c \

SRC_LIBC=	ft_strnew_fill.c \
		ft_putstr_size.c \
		ft_atoi.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_swap.c \
		ft_strdup.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isprint.c \
		ft_isascii.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlcat.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_itoa_long.c \
		ft_itoa_proper_base.c \
		ft_itoa_size_t.c \
		ft_itoa_intmax.c \
		ft_itoa_long_long.c \
		ft_putchar.c \
		ft_litoa_proper_base.c \
		ft_llitoa_proper_base.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_ulitoa.c \
		ft_uitoa.c \
		ft_putnbr.c \
		ft_umaxitoa.c \
		ft_umaxitoa_proper_base.c \
		ft_ullitoa.c \
		ft_umaxitoa.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_stitoa_proper_base.c \
		ft_putnbr_fd.c \
		ft_tolower.c \
		ft_putendl_fd.c \
		ft_strlen.c \
		ft_lstadd.c \
		ft_lstdel.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_issign.c \
		ft_strnchr.c \
		ft_tounicode.c \
		ft_putadress.c \
		ft_uitoa_size_t.c \
		ft_strndup.c \
		ft_putchar_print.c \
		get_next_line.c \
		ft_sort_int_table.c \
		ft_find_max_tab.c \
		ft_find_min_tab.c \
		ft_strlchr.c \
		ft_count_char.c

OBJ_LIBC=$(LIBC:.c=.o)
OBJ_PRINTF=$(PRINTF:.c=.o)

PRINTF=	$(addprefix $(SRC_PATH)/$(PRINTF_PATH)/, $(SRC_PRINTF))
LIBC=	$(addprefix $(SRC_PATH)/, $(SRC_LIBC))
INC=	$(addprefix $(INC_PATH)/, $(INC_FILES))


all: $(NAME)

$(NAME): $(OBJ_LIBC) $(OBJ_PRINTF)
	@ar rc $(NAME) $(OBJ_LIBC) $(OBJ_PRINTF)
	@ranlib $(NAME)
	@echo "\033[1;34m$(NAME)\033[1;32m...compiled\t✓\033[0m"


%.o : %.c
	@$(CC) $(FLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ_LIBC) $(OBJ_PRINTF)

fclean: clean
	@rm -rf $(NAME)

re:
	make fclean
	make
