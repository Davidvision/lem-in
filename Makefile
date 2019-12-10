# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hklein <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/09 19:06:01 by hklein            #+#    #+#              #
#    Updated: 2019/02/25 22:29:42 by hklein           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

MAKE_L = make -C
LIB_NAME = libft.a
LIB_PATH = libft/

CFLAGS = -Wall -Wextra -Werror

SRC1 = srcs/lm_ants_distribution.c\
	   srcs/lm_del_lists.c\
	   srcs/lm_init_path.c\
	   srcs/lm_parser.c\
	   srcs/lm_check_inputs.c\
	   srcs/lm_free_lists.c\
	   srcs/lm_init_search.c\
	   srcs/lm_send_ants.c\
	   srcs/lm_create_hole.c\
	   srcs/lm_init_ants.c\
	   srcs/lm_main.c\
	   srcs/lm_solve.c\
	   srcs/lm_create_link.c\
	   srcs/lm_init_lm.c\
	   srcs/lm_manage_lists.c\
	   srcs/lm_update_flow.c

NAME = lem-in

HDRS = includes/

OBJ1 = $(SRC1:.c=.o)

all: libft/libft.a $(NAME)

libft/libft.a:
	$(MAKE_L) $(LIB_PATH)

$(NAME): libft/libft.a $(OBJ1)
	$(CC) $(CFLAGS) $(LIB_PATH)$(LIB_NAME) $(OBJ1) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -I $(HDRS) -o $@ -c $<

clean:
	$(MAKE_L) $(LIB_PATH) clean
	rm -rf $(OBJ1)

fclean: clean
	$(MAKE_L) $(LIB_PATH) fclean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean
