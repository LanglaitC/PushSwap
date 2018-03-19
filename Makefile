# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clanglai <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/07 15:30:47 by clanglai          #+#    #+#              #
#    Updated: 2018/03/19 16:19:13 by clanglai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc

FLAGS=-Wall -Wextra -Werror
PUSHSWAP_NAME=push_swap
CHECKER_NAME=checker
LIB_PATH =libft
LIB_NAME=lftprintf
LIBG_PATH=minilibx
LIBG=lmlx
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
SRC_PUSHWAP= $(addprefix $(PATH_SRC)/, $(SRC_NAME_PUSHSWAP))
SRC_CHECKER= $(addprefix $(PATH_SRC)/, $(SRC_NAME_CHECKER))
SRC_BOTH= $(addprefix $(PATH_SRC)/, $(SRC_NAME_BOTH))

all : $(SRC_BOTH) $(PUSHSWAP_NAME) $(CHECKER_NAME)

$(PUSHSWAP_NAME) : $(OBJ) $(OBJ_PUSHSWAP)
	make -C libft
	make -C libft
	gcc -o $(PUSHSWAP_NAME) $(FLAGS) $(OBJ) $(SRC_PUSHSWAP) -L$(LIB_PATH) \
	-$(LIB_NAME) -L$(LIBG_PATH) -$(LIBG) -framework $(FRAMEWORK1) -framework \
	$(FRAMEWORK2)

$(CHECKER_NAME) : $(OBJ) $(OBJ_CHECKER)
	make -C libft
	make -C minilibx
	gcc $(FLAGS) -o $(CHECKER_NAME) $(FLAGS) $(OBJ) $(OBJ_CHECKER) \
	-L$(LIB_PATH) -$(LIB_NAME) -L$(LIBG_PATH) -$(LIBG) -framework \
	$(FRAMEWORK1) -framework $(FRAMEWORK2) 
%.o : %.c
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(PUSHSWAP_NAME) $(CHECKER_NAME)

re:
	make fclean
	make
