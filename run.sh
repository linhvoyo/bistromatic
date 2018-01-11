#!/bin/bash

make -C libft/ fclean && make -C libft/ && make clean -C libft/
gcc -g -I./libft/includes/ -L./libft -lft  *.c
gcc -c -g -I libft/includes *.c


