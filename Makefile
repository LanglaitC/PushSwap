# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clanglai <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/07 15:30:47 by clanglai          #+#    #+#              #
#    Updated: 2018/03/20 16:15:52 by clanglai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
cyan = /bin/echo -e "\x1b[36m\#\# $1\x1b[0m"
FLAGS=-Wall -Wextra -Werror
PUSHSWAP_NAME=push_swap
CHECKER_NAME=checker
LIBC=libft/libftprintf.a
LIBG=minilibx/mlx.a
LIB_PATH =libft
LIB_NAME=lftprintf
LIBG_PATH=minilibx
LIBG_NAME=lmlx
FRAMEWORK1=OpenGl
PATH_SRC=srcs
FRAMEWORK2=AppKit
SRC_NAME_BOTH=ft_actions_2.c \
			ft_checker.c \
			ft_pushswap.c \
			ft_sort.c \
			ft_actions.c \
			ft_parse.c \
			ft_concate.c \
			ft_aux_fonc.c \
			ft_aux_fonc_2.c \
			ft_sort_2.c \
			ft_get_arg.c \
			ft_visualize.c \
			ft_visualize_2.c
SRC_NAME_PUSHSWAP=	ft_pushswap_main.c
SRC_NAME_CHECKER=	ft_checker_main.c
OBJ=$(SRC_BOTH:.c=.o)
OBJ_PUSHSWAP=$(SRC_PUSHWAP:.c=.o)
OBJ_CHECKER=$(SRC_CHECKER:.c=.o)
SRC_PUSHSWAP= $(addprefix $(PATH_SRC)/, $(SRC_NAME_PUSHSWAP))
SRC_CHECKER= $(addprefix $(PATH_SRC)/, $(SRC_NAME_CHECKER))
SRC_BOTH= $(addprefix $(PATH_SRC)/, $(SRC_NAME_BOTH))

all : $(LIBC) $(LIBG) $(SRC_BOTH) $(PUSHSWAP_NAME) $(CHECKER_NAME)

$(LIBC):
	@make -C $(LIB_PATH)

$(LIBG):
	@make -C $(LIBG_PATH)

$(PUSHSWAP_NAME): $(OBJ) $(OBJ_PUSHSWAP)
	@gcc -o $(PUSHSWAP_NAME) $(FLAGS) $(OBJ) $(SRC_PUSHSWAP) -L$(LIB_PATH) \
	-$(LIB_NAME) -L$(LIBG_PATH) -$(LIBG_NAME) -framework $(FRAMEWORK1) \
	-framework $(FRAMEWORK2)
	@echo "\033[1;34m$(PUSHSWAP_NAME)\033[1;32m...compiled\t\t✓\033[0m"

$(CHECKER_NAME) : $(OBJ) $(OBJ_CHECKER)
	@gcc $(FLAGS) -o $(CHECKER_NAME) $(FLAGS) $(OBJ) $(OBJ_CHECKER) \
	-L$(LIB_PATH) -$(LIB_NAME) -L$(LIBG_PATH) -$(LIBG_NAME) -framework \
	$(FRAMEWORK1) -framework $(FRAMEWORK2)
	@echo "\033[1;34m$(CHECKER_NAME)\033[1;32m...compiled\t\t✓\033[0m"

%.o : %.c
	@$(CC) $(FLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ)
	@make clean -C $(LIB_PATH)
	@echo "\033[1;34mpush_swap\033[1;33m obj files removed\t\033[1;31m✓\033[0m"
	@echo "\033[1;34mchecker\033[1;33m obj files removed\t\033[1;31m✓\033[0m"

fclean : clean
	@rm -rf $(PUSHSWAP_NAME) $(CHECKER_NAME)
	@make fclean -C $(LIB_PATH)
	@echo "\033[1;34mpush_swap\033[1;33m exec removed\t\t\033[1;31m✓\033[0m"
	@echo "\033[1;34mchecker\033[1;33m exec removed\t\t\033[1;31m✓\033[0m"

re:
	@make fclean
	@make
