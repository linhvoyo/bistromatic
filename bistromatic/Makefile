NAME = calc

$(NAME):
	@make -C libft/ fclean && make -C libft/ && make clean -C libft/
	@gcc -Wall -Wextra -Werror -I./includes/ -L./libft -lft -o $(NAME) ./srcs/*.c
	@gcc -Wall -Wextra -Werror -c -I./includes/ ./srcs/*.c

all: $(NAME)

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all

