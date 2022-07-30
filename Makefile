# _*_ MakeFile _*_

CC := cc
CFLAGS := -I /usr/local/include -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit -fsanitize=address
SRCS =	allocation.c\ 
		color.c\     
		fractol.c\       
		hook.c\       
		math.c\       
		zoom.c
		
NAME := fractol.a

OBJS := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar crs $(NAME) $(OBJS)	
%.o : %.c
	$(CC) $(CFLAGS) -c $(SRCS)

clean : 
	rm -f *.o
fclean : clean
	rm -f $(NAME)
re : fclean all

