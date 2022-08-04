# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 16:38:04 by kadjane           #+#    #+#              #
#    Updated: 2022/08/04 18:12:05 by kadjane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fractol

CFLAGS := -Wall -Wextra -Werror -I /usr/local/include -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit #-fsanitize=address -g

SRCS = color.c fractol.c hook.c math.c ft_strncmp.c main.c ft_render.c ft_putstr.c fractol_bonus.c hook_bonus.c

$(NAME) : $(SRCS)

all: $(NAME)
	@gcc $(CFLAGS) $(SRCS) -o $(NAME)
	
bonus : all

clean : 
	@rm $(NAME) 

fclean : clean

re : fclean all
