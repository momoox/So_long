# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgeisler <mgeisler@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/27 22:16:25 by mgeisler          #+#    #+#              #
#    Updated: 2023/07/17 16:08:23 by mgeisler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = so_long.c parser.c init_map.c utils.c utils_2.c print_test.c ft_strjoin.c ft_split.c valid_map.c free_all.c\
		playable_map.c render_map.c load_img.c game_init.c find_pos.c anim.c anim_2.c ft_putstr.c move.c ft_itoa.c\
		gnl/get_next_line.c gnl/get_next_line_utils.c\

OBJECTS = $(SRCS:.c=.o)

GCC = gcc -Wall -Werror -Wextra -g3 -fsanitize=address

all : $(NAME)

$(NAME): $(OBJECTS)
		@ $(GCC) $(SRCS) -o $(NAME) MLX42/libmlx42.a -I include -lglfw -L "/opt/homebrew/Cellar/glfw/3.3.8/lib/"

%.o: %.c 
		@ $(GCC) -c $?
clean:
		@ rm -f $(OBJECTS)

fclean: clean
		@ rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test