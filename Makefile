NAME = 	push_swap

SRCS = 	push_swap.c \

OBJS = 	push_swap.o \

FLAGS = -Wall -Wextra -Werror

LIB = make -C libft/

H_DIR = ./

LIB_DIR = ./libft/

all: $(NAME)

$(NAME):
	$(LIB)
	gcc -c $(SRCS) -I $(H_DIR) -I $(LIB_DIR) $(FLAGS)
	gcc $(OBJS) -o $(NAME) -L $(LIB_DIR) -lft

clean:
	rm -f $(OBJS)
	make clean -C $(LIB_DIR)

fclean:
	rm -f $(NAME)
	rm -f $(OBJS)
	make fclean -C $(LIB_DIR)

re: fclean all
