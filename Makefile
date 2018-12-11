CC = gcc
CFLAGS = -Wall -Wextra -Werror --pedantic -O2
LIB = ./libft/libft.a
NAME = fillit

all: $(NAME)

$(NAME): $(NAME).o helpers.o $(LIB)
	$(CC) $(CFLAGS)  $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(LIB):
	make -C ./libft 

clean:
	rm -r *.o
	make clean -C ./libft

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)
