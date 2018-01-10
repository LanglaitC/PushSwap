# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clanglai <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/07 15:30:47 by clanglai          #+#    #+#              #
#    Updated: 2018/01/10 09:53:08 by clanglai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc

FLAG=-Wall -Wextra -Werror

PUSHSWAP_NAME=push_swap
CHECKER_NAME=checker
LIB_PATH =libft
LIB_NAME=lftprintf
SRC_BOTH=ft_actions_2.c \
			ft_checker.c \
			ft_pushswap.c \
			ft_sort.c \
			ft_actions.c \
			ft_parse.c
SRC_PUSHSWAP=ft_pushswap_main.c
SRC_CHECKER=ft_checker_main.c
OBJ=$(SRC_BOTH:.c=.o)
OBJ_PUSHSWAP=$(SRC_PUSHWAP:.c=.o)
OBJ_CHECKER=$(SRC_CHECKER:.c=.o)

all : $(PUSHSWAP_NAME) $(CHECKER_NAME)

$(PUSHSWAP_NAME) : $(OBJ) $(OBJ_PUSHSWAP)
	make -C libft
	gcc -o $(PUSHSWAP_NAME) $(OBJ) $(SRC_PUSHSWAP) -L$(LIB_PATH) -$(LIB_NAME)

$(CHECKER_NAME) : $(OBJ) $(OBJ_CHECKER)
	make -C libft
	gcc -o $(CHECKER_NAME) $(OBJ) $(OBJ_CHECKER) -L$(LIB_PATH) -$(LIB_NAME)

clean:
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(PUSHSWAP_NAME) $(CHECKER_NAME)

re:
	make fclean
	make
