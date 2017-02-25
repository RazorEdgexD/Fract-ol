# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/08 13:28:10 by aosobliv          #+#    #+#              #
#    Updated: 2017/02/25 14:50:18 by aosobliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

IDIR = includes/

VPATH = src:includes

FLAGS = -O3 -Wall -Wextra -Werror -I$(IDIR) -g

MLX = -lmlx -framework AppKit -framework OpenGl

LIB = libft/libft.a

SRCS = main.c										\
			ft_tools.c								\
			kox.c									\
			mendel.c								\
			julia.c									\
			tri_serp.c								\
			burningship.c							\
			ft_hooks.c								\
			carpet_serp.c							\
			kox_kurve.c								\
			sinus.c									\
			bio.c									\
			put_info.c								\
			ft_tools2.c								\
			ft_tools3.c								\

BINS = $(SRCS:.c=.o)

all: $(NAME)

makelib:
	make -C libft/

libclean:
	make -C libft/ clean

libfclean:
	make -C libft/ fclean

$(NAME): $(BINS)
	make -C libft/
	gcc -o $(NAME) $(FLAGS) $(BINS) $(MLX) $(LIB)

%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

clean:
	make -C libft/ clean
	/bin/rm -f $(BINS)

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all
