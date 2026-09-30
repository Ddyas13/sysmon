CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -I include
SRC     = src/main.c src/ft_put.c src/ft_atoi.c \
          src/cpu.c src/mem.c src/proc.c src/display.c
OBJ     = $(SRC:.c=.o)
NAME    = sysmon

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
