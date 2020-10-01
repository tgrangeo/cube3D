# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgrangeo <tgrangeo@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/23 18:40:57 by thomasgrang       #+#    #+#              #
#    Updated: 2020/10/01 14:36:52 by tgrangeo         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #


SRCS = srcs/key.c srcs/ft_image.c srcs/parse_config.c srcs/parse_conf_2.c srcs/ft_init.c srcs/raycasting.c srcs/move.c srcs/loop.c srcs/check_map.c srcs/texture.c srcs/sprite.c srcs/parse_conf_3.c

NAME = cube3d.a
HEADER = includes/cube3d.h
FLAGS = -Werror -Wall -Wextra
FRAMEWORKS = -framework OpenGL -framework AppKit
MINILIBX = minilibx/libmlx.a
LIBFT = libft/libft.a
RM = rm -f
OBJS = ${SRCS:.c=.o}

all: $(MINILIBX) $(LIBFT) $(NAME)
	gcc $(FRAMEWORKS) $(FLAGS) srcs/main.c $(NAME) $(LIBFT)

%.o: %.c $(LIBFT) $(MINILIBX) $(HEADER)
	gcc $(FLAGS) -c $< -o $@

$(NAME):$(OBJS) $(HEADER)
	cp $(LIBFT) ./$(NAME)
	cp $(MINILIBX) ./$(NAME)
	ar rcs $(NAME) $(OBJS)

$(MINILIBX):
	cd minilibx/ && $(MAKE)
	
$(LIBFT):
	cd libft/ && $(MAKE)

clean:
	$(RM) $(OBJS)
	cd minilibx/ && $(MAKE) clean
	cd libft/ && $(MAKE) fclean

fclean: clean
	$(RM) $(NAME)
	$(RM) a.out

re: fclean all
