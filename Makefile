# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgeisler <mgeisler@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/27 22:16:25 by mgeisler          #+#    #+#              #
#    Updated: 2023/07/03 19:34:51 by mgeisler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = so_long.c parser.c init_map.c utils.c print_test.c ft_strjoin.c ft_split.c valid_map.c\
		playable_map.c \
		gnl/get_next_line.c gnl/get_next_line_utils.c\

OBJECTS = $(SRCS:.c=.o)

GCC = gcc -Wall -Werror -Wextra -g3

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