# _*_ MakeFile _*_
NAME := fractol
CFLAGS := -I /usr/local/include -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit -fsanitize=address
SRCS = color.c fractol.c hook.c math.c ft_strncmp.c main.c ft_render.c

$(NAME) : $(SRCS)

all: $(NAME)
	gcc $(CFLAGS)  $(SRCS) -o $(NAME)

clean : 
	@rm $(NAME)

fclean : clean

re : fclean all

