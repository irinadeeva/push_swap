NAME = push_swap

SRCS = push_swap.c \
	  
OBJS = $(SRCS:.c=.o)

GCCFLAGS = -Wall -Wextra -Werror

all: $(NAME)
		@make -C ./libft
		@gcc $(GCCFLAGS) - o $(NAME) $(OBJS) \
			-L ./libft/ -I ./ -I ./libft

clean:
		@rm -f $(OBJS)
		@make clean -C ./libft

fclean: clean
		@rm -f $(NAME)
		@make fclean -C ./libft

re: fclean all