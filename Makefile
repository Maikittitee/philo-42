NAME = philosopher

CC = gcc

FLAGS = -Wall -Werror -Wextra -g

LIBFT_PATH = lib/libft
PRINTF_PATH = lib/libftprintf
SRCS_PATH = src/

LIBFT_FLAG = -Llib/libft -lft
PRINTF_FLAG = -Llib/libftprintf -lftprintf 

LIBFT = $(LIBFT_PATH)/libft.a
PRINTF = $(PRINTF_PATH)/libftprintf.a

SRCS_fILE = main.c\
		check_arg.c\
		init_data.c\
		debug.c\
		create_philos_and_forks.c\
		start.c\
		time.c

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_fILE))

OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(PRINTF) $(NAME)

$(LIBFT): 
	make -C $(LIBFT_PATH)

$(PRINTF):
	make -C $(PRINTF_PATH)

%.o:%.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(LIBFT_FLAG) $(PRINTF_FLAG) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS) $(LIBFT_PATH)/*.o Lib/libftprintf/*.o

fclean: clean
	rm -rf $(NAME) $(LIBFT_PATH)/*.a Lib/libftprintf/*.a

re: fclean all

run:
	./push_swap $(ARG)

.PHONY: clean fclean all re