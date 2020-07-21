# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyhuet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/07 12:02:11 by cyhuet            #+#    #+#              #
#    Updated: 2019/10/12 16:49:44 by cyhuet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = libft

OBJ_DIR = obj

SRC =	core/dispatch.c core/flags.c core/ft_printf.c core/get_numbers.c core/length.c \
		utils/add_zero_front.c utils/fill_space.c utils/fill_zero.c \
		utils/ft_get_index.c utils/ft_itoa_base.c \
		utils/ft_pow.c utils/ft_pow_long.c utils/ft_strrev.c utils/itoa.c utils/put_str_char.c \
		display/display_c.c display/display_d_i.c display/display_p.c \
		display/display_percent.c display/display_s.c display/display_u.c \
		display/display_x.c display/helper.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I. -c

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/core
	mkdir -p $(OBJ_DIR)/utils
	mkdir -p $(OBJ_DIR)/display

$(OBJ_DIR)/%.o:./%.c
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJ_DIR) $(OBJ)
	make -C $(LIBFT)
	cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -rf $(OBJ_DIR)
	make clean -C libft/

fclean: clean
	rm -f $(NAME)
	make fclean -C libft/


re: fclean all

.PHONY: all clean fclean re
