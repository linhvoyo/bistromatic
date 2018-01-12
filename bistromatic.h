/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bistromatic.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroshiusui <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 20:10:08 by hiroshius         #+#    #+#             */
/*   Updated: 2018/01/11 22:09:45 by hiroshius        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BISTROMATIC_H
# define BISTROMATIC_H
# include "./libft/includes/libft.h"
# include <stdio.h>

typedef struct              s_linked_list
{
    char                    *data;
    struct s_linked_list    *next;
}                           linked_list;

char *add(char *s1, char *s2);
char *subtract(char *s1, char *s2);
void truncate_zeros(char **str);
char *pad_left(char *s1, int n);
void add_link(linked_list **list, char *str);
linked_list *create_link(char *str);
char *summate_linked_list(linked_list *list);
void initialize_zero(char *str, int length);
int pop_digit(char *str);
int get_rightmost_digit(char *str);
void shift_right(char **string_pointer);
char *pad_right(char *str, int number_of_zeros);
char *multiply(char *str1, char *str2);
int zeroed(char *str);
int is_str1_smaller(char *str1, char *str2);
void print_linked_list(linked_list *list);
char *divide(char *dividend, char *divisor);
int number_cmp(char *str1, char *str2);

#endif
