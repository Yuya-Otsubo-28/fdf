NAME = fdf
SRCS = ./src/data_init.c \
		./src/free_utils.c \
		./src/main.c \
		./src/make_map.c \
		./src/my_mlx_pixel_put.c
OBJS = $(SRCS:.c=.o)
INCLUDES = -I./includes -I./libmlx -I./libft
CC = cc
CFLAGS = -Wall -Wextra -Werror -L./libmlx -L./libft -fsanitize=address
LIBS = -lft -lmlx_Linux -lX11 -lXext
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
MLX_PATH = ./libmlx
MLX = $(MLX_PATH)/libmlx_Linux.a

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBS)  -o $@ 

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT) :
	make -C $(LIBFT_PATH)

$(MLX) :
	make -C $(MLX_PATH)

clean :
	$(RM) $(OBJS)
	make clean -C $(LIBFT_PATH)
	make clean -C $(MLX_PATH)

fclean : clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_PATH)

re : fclean all

.PHONY : all clean fclean re
