# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: thomasgrangeon <thomasgrangeon@student.    +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2020/02/23 18:40:57 by thomasgrang  #+#   ##    ##    #+#        #
#    Updated: 2020/02/23 18:54:48 by thomasgrang ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #


FLAGS = -Werror -Wall -Wextra
FRAMEWORKS = -framework OpenGL -framework AppKit
MINILIBX = minilibx_opengl/libmlx.a
LIBFT = libft/libft.a

all: $(MINILIBX)
	gcc $(FRAMEWORKS) $(FLAGS) main.c $(MINILIBX)

$(MINILIBX):
	cd minilibx_opengl/ && $(MAKE)

clean:
	cd minilibx_opengl/ && $(MAKE) clean

fclean: clean
	rm a.out