NAME = philo

CC = cc

FLAGS = -Wall -Werror -Wextra -g -pthread

LIBFT_PATH = lib/libft
SRCS_PATH = src/

LIBFT_FLAG = -Llib/libft -lft

LIBFT = $(LIBFT_PATH)/libft.a

SRCS_fILE = main.c\
		check_arg.c\
		init_data.c\
		create_philos_and_forks.c\
		start.c\
		time.c\
		routine.c\
		die.c\
		free.c

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_fILE))

OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(PRINTF) $(NAME)

$(LIBFT): 
	make -C $(LIBFT_PATH)

%.o:%.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(LIBFT_FLAG) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS) $(LIBFT_PATH)/*.o

fclean: clean
	rm -rf $(NAME) $(LIBFT_PATH)/*.a

re: fclean all

.PHONY: clean fclean all re