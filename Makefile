SRC = \
	fractol.c \
	complex.c \
	hook.c \
	math_utils.c \
	mandelbrot.c \
	julia.c \
	burning_ship.c \
	view.c \
	carolle.c \

OBJ = ${SRC:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf
NAME = fractol
PRINTF = "./ft_printf"
MLX = "./mlx-linux"
LIBS	= -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz libftprintf.a libmlx.a

all: ${NAME}

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	make -C $(PRINTF)
	mv $(PRINTF)/libftprintf.a .
	make all -C $(MLX)
	mv $(MLX)/libmlx.a .
	$(CC) $(OBJ) $(LIBS) -o $(NAME)

clean:
	make clean -C $(PRINTF)
	make clean -C $(MLX)
	$(RM) $(OBJ)

fclean: clean
	make fclean -C $(PRINTF)
	$(RM) $(NAME) libftprintf.a
	$(RM) $(NAME) libmlx.a

re: fclean all

.PHONY : all clean fclean re
