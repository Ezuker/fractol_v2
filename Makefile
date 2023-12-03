SRC = \
	fractol.c \
	complex.c \
	hook.c \

OBJ = ${SRC:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf
NAME = fractol
PRINTF = "./ft_printf"
LIBS	= -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz libftprintf.a libmlx.a

all: ${NAME}

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	make -C $(PRINTF)
	mv $(PRINTF)/libftprintf.a .
	$(CC) $(OBJ) $(LIBS) -o $(NAME)

clean:
	make clean -C $(PRINTF)
	$(RM) $(OBJ)

fclean: clean
	make fclean -C $(PRINTF)
	$(RM) $(NAME) libftprintf.a

re: fclean all

.PHONY : all clean fclean re
