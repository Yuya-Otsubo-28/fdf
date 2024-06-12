NAME = fdf
SRCS = 
OBJS = $(SRCS:.c.o)
INCLUDES = -I./includes
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_PATH = ./libft
LIBFT = libft.a

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $(LIBFT_PATH)/$(LIBFT) $(OBJS) -o $@

$(OBJS) : $(SRCS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT) :
	make -C $(LIBFT_PATH)

clean :
	$(RM) $(OBJS)
	make clean -C $(LIBFT_PATH)

fclean : clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_PATH)

re : fclean all

.PHONY : all clean fclean re
	
	
