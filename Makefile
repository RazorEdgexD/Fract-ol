# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/08 13:28:10 by aosobliv          #+#    #+#              #
#    Updated: 2017/02/14 20:44:13 by aosobliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

IDIR = includes/

VPATH = src:includes

FLAGS = -Wall -Wextra -Werror -I$(IDIR) -g

MLX = -lmlx -framework AppKit -framework OpenGl

LIB = libft/libft.a

SRCS = main.c										\
			ft_tools.c								\
			kox.c									\
			mendel.c								\
			julia.c									\
			burningship.c							\
			ft_hooks.c								\

BINS = $(SRCS:.c=.o)

all: $(NAME)

makelib:
	make -C libft/

libclean:
	make -C libft/ clean

libfclean:
	make -C libft/ fclean

$(NAME): $(BINS)
	gcc -o $(NAME) $(BINS) $(FLAGS) $(MLX) $(LIB)

%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

clean:
	/bin/rm -f $(BINS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
