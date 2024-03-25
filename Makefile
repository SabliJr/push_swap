NAME = push_swap

RED:="\033[1;31m"
GREEN:="\033[1;32m"
PURPLE:="\033[1;35m"
CYAN:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"

LIBFT_PATH = ./libft
PUSH_SWAP = ./src/push_swap.c \
			./src/ft_init.c \
			./src/indexing.c \
			./src/sort_utils.c \
			./src/handle_sort.c \
			./src/ope1.c \
			./src/ope2.c \
			./src/ope3.c \
			./src/ope4.c \
			./src/quick_sort.c

SRCS = ${PUSH_SWAP}
OBJS = ${SRCS:.c=.o}

CC = cc
CFLAGES = -Wall -Wextra -Werror -g3

.c.o:
	${CC} ${CFLAGES} -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
		@make -C ${LIBFT_PATH}
		${CC} ${CFLAGES} ${OBJS} -L${LIBFT_PATH} -lft -o $(NAME)
		echo $(GREEN) "[OK COMPILED]" $(EOC)

all: $(NAME)

clean:
	rm -f $(OBJS)
	@make clean -C ${LIBFT_PATH}
	echo $(PURPLE) "[🧹Cleaning...🧹]" $(EOC)

fclean:
	rm -f $(NAME)
	make fclean -C ${LIBFT_PATH}

re: fclean all
.PHONY: all clean fclean re