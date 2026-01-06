CPP = c++

CPPFLAGS = -Wall -Wextra -Werror

SRC = ./bonus/mlx/mlx_hooks_bonus.c ./bonus/mlx/mlx_bonus.c \
                ./bonus/parsing/checks_bonus.c ./bonus/parsing/checks2_bonus.c \

OBJS = $(SRC:.c=.o)

NAME = cub3d

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CPP) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re