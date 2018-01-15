#!/bin/bash

#make -C libft/ fclean && make -C libft/ && make clean -C libft/
gcc -g -I./includes/ -L./libft -lft -o calc ./srcs/*.c
#gcc -c -g -I./includes ./srcs/*.c
#rm *.o

