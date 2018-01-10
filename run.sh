#!/bin/bash

make -C libft/ fclean && make -C libft/ && make clean -C libft/
gcc -g -Wall -Wextra -Werror -I./libft/includes/ -L./libft -lft  *.c
gcc -c -g -Wall -Wextra -Werror -I libft/includes *.c


