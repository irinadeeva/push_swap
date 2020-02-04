NAME = 	push_swap

SRCS = 	push_swap.c \
		verification.c\
		create_stack.c\
		commads.c\
		throwing.c\
		sort_3.c\
		cost_of_operation.c\

OBJS = 	push_swap.o \
		verification.o\
		create_stack.o\
		commads.o\
		throwing.o\
		sort_3.o\
		cost_of_operation.o\

FLAGS = -Wall -Wextra -Werror

LIB = make -C libft/

H_DIR = ft_push_swap.h

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
