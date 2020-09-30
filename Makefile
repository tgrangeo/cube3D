# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thomasgrangeon <thomasgrangeon@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/23 18:40:57 by thomasgrang       #+#    #+#              #
#    Updated: 2020/09/08 16:31:41 by thomasgrang      ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #


SRCS = key.c ft_image.c parse_config.c parse_conf_2.c ft_init.c raycasting.c move.c loop.c check_map.c texture.c sprite.c

NAME = cube3d.a
HEADER = includes/cube3d.h
FLAGS = -Werror -Wall -Wextra
FRAMEWORKS = -framework OpenGL -framework AppKit
MINILIBX = minilibx/libmlx.a
LIBFT = libft/libft.a
RM = rm -f
OBJS = ${SRCS:.c=.o}

all: $(MINILIBX) $(LIBFT) $(NAME)
	gcc $(FRAMEWORKS) $(FLAGS) main.c $(NAME) $(LIBFT)

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
