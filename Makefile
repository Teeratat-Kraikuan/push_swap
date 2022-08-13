NAME = push_swap

FT_UTILS = 	check_arg.c \
			ft_utils.c \
			change_arg.c
UTILS = $(addprefix srcs/ft_utils/, $(FT_UTILS))

FT_PUSH_SWAP =	insertion_sort.c \
				quick_sort1.c \
				quick_sort2.c \
				bubble_sort.c
PUSH_SWAP = $(addprefix srcs/push_swap/, $(FT_PUSH_SWAP))

FT_STK =	ft_stack_utils1.c \
			ft_stack_utils2.c \
			instructions1.c \
			instructions2.c \
			instructions3.c
STK = $(addprefix srcs/stack/, $(FT_STK))

INCS_DIR = includes/

SRCS = $(UTILS) $(PUSH_SWAP) $(STK) main.c
OBJS = $(SRCS:.c=.o)


LIB = ar -rcs
FLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJS)
		gcc $(FLAGS) $(OBJS) -o $@

$(OBJS): %.o: %.c
		gcc $(FLAGS) -c $< -o $@ -I $(INCS_DIR)

clean :
		rm -f $(OBJS)

fclean : clean
		rm -f $(NAME)

re : fclean all
