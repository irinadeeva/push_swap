NAME1 = push_swap

NAME2 = checker

LIB = libftprintf.a

SRCS1 = push_swap.c \
		verification.c\
		create_stack.c\
		get_linked_list.c\
		commads_ab.c\
		commads_a.c\
		commads_b.c\
		throwing_to_a.c\
		throwing_to_b.c\
		cost_in_a.c\
		cost_in_b.c\
		cost_extreme_cases.c\
		sort_3.c\
		cost_of_operation.c\
		error.c\
		display.c

SRCS2 = checker.c \
		verification.c\
		create_stack.c\
		commads_ab.c\
		commads_a.c\
		commads_b.c\
		throwing_to_a.c\
		throwing_to_b.c\
		sort_3.c\
		get_linked_list.c\
		scan.c\
		error.c\
		free.c\
		display.c


DIR_O = obj/

OBJS1 = $(addprefix $(DIR_O),$(SRCS1:.c=.o))

OBJS2 = $(addprefix $(DIR_O),$(SRCS2:.c=.o))

FLAGS = -Wall -Wextra -Werror

H_DIR1 = ft_push_swap.h

H_DIR2 = ft_checker.h

LIB_DIR =  ./ft_printf/

.PHONY: all clean fclean re

all: $(LIB) $(NAME1) $(NAME2)

$(LIB):
	@make -C libft/
	@make -C ft_printf/

$(NAME1): $(OBJS1)
	gcc -c $(FLAGS) $(SRCS1) -I $(H_DIR1) -I $(LIB_DIR)
	gcc $(OBJS1) -o $(NAME1) -L $(LIB_DIR) -lftprintf

$(DIR_O)%.o: $(DIR_S)%.c
	@mkdir -p $(DIR_O)
	$(CC) $(FLAGS) -o $@ -c $<

$(NAME2): $(OBJS2)
	gcc -c $(FLAGS) $(SRCS2) -I $(H_DIR2) -I $(LIB_DIR)
	gcc $(OBJS2) -o $(NAME2) -L $(LIB_DIR) -lftprintf

clean:
	rm -rf $(DIR_O)
	@make -C libft/ clean
	@make -C ft_printf/ clean

fclean: clean
	rm -f $(NAME1)
	rm -f $(NAME2)
	@make -C libft/ fclean
	@make -C ft_printf/ fclean

re: fclean all
