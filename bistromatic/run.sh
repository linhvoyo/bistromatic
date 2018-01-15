#!/bin/bash

#make -C libft/ fclean && make -C libft/ && make clean -C libft/
gcc -Wall -Wextra -Werror -I./includes/ -L./libft -lft -o calc ./srcs/*.c
#gcc -c -g -I./includes ./srcs/*.c
#rm *.o

