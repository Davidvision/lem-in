# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hklein <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 17:37:22 by hklein            #+#    #+#              #
#    Updated: 2019/02/14 19:37:56 by hklein           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

AR = ar rc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf/ft_printf.c\
	ft_printf/ft_printf_c_stock_op.c\
	ft_printf/ft_printf_parsing.c\
	ft_printf/ft_printf_set_res.c\
	ft_printf/ft_printf_get_var.c\
	ft_printf/ft_printf_var_op.c\
	ft_printf/ft_printf_var_op_2.c\
	ft_printf/ft_printf_floats_op.c\
	ft_printf/ft_printf_format_var.c\
	ft_printf/ft_printf_colors.c\
	ft_printf/ft_printf_format_unicode.c\
	ft_atoi.c\
	ft_bzero.c\
	ft_isalnum.c\
	ft_isalpha.c\
	ft_isascii.c\
	ft_isdigit.c\
	ft_isprint.c\
	ft_itoa.c\
	ft_lstadd.c\
	ft_lstdel.c\
	ft_lstdelone.c\
	ft_lstiter.c\
	ft_lstmap.c\
	ft_lstnew.c\
	ft_memalloc.c\
	ft_memccpy.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_memcpy.c\
	ft_memdel.c\
	ft_memmove.c\
	ft_memset.c\
	ft_putchar.c\
	ft_putchar_fd.c\
	ft_putendl.c\
	ft_putendl_fd.c\
	ft_putnbr.c\
	ft_putnbr_fd.c\
	ft_putstr.c\
	ft_putstr_fd.c\
	ft_strcat.c\
	ft_strchr.c\
	ft_strclr.c\
	ft_strcmp.c\
	ft_strcpy.c\
	ft_strdel.c\
	ft_strdup.c\
	ft_strequ.c\
	ft_striter.c\
	ft_striteri.c\
	ft_strjoin.c\
	ft_strlcat.c\
	ft_strlen.c\
	ft_strmap.c\
	ft_strmapi.c\
	ft_strncat.c\
	ft_strncmp.c\
	ft_strncpy.c\
	ft_strnequ.c\
	ft_strnew.c\
	ft_strnstr.c\
	ft_strrchr.c\
	ft_strsplit.c\
	ft_strstr.c\
	ft_strsub.c\
	ft_strtrim.c\
	ft_tolower.c\
	ft_toupper.c\
	ft_lstsize.c\
	ft_intswap.c\
	ft_strnjoin.c\
	ft_strcapitalize.c\
	ft_strrev.c\
	ft_str_realloc.c\
	ft_strjoinf.c\
	ft_strsubf.c\
	ft_strclen.c\
	ft_strnjoinf.c\
	ft_tab_realloc.c\
	get_next_line.c\
	ft_strjoincharf.c\
	ft_itoa_base.c\
	ft_utoa_base.c\
	ft_lltoa_base.c\
	ft_strdup_secured.c\
	ft_countifchar.c\
	ft_strsubf_unsecured.c\
	ft_int_len.c\
	ft_int_pow.c\
	ft_wcslen.c\
	ft_tabdup.c\
	ft_is_sort.c\
	ft_atol.c\
	ft_find_med.c\
	ft_quicksort.c\
	ft_tab_len.c\
	ft_is_str_digit.c\
	ft_tabdel.c

NAME = libft.a

HDRS = ./

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
		@$(AR) $(NAME) $(OBJ)
			@ranlib $(NAME)
%.o: %.c
		@$(CC) $(CFLAGS) -c -I $(HDRS) $< -o $@
clean :
		@rm -rf $(OBJ)
fclean : clean
		@rm -rf $(NAME)

re : fclean all

.PHONY : clean
