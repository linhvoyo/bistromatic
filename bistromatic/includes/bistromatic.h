/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bistromatic.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 22:58:59 by lilam             #+#    #+#             */
/*   Updated: 2018/01/15 09:10:57 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BISTROMATIC_H
# define BISTROMATIC_H
# include "../libft/includes/libft.h"
# include <stdio.h>

typedef struct              s_linked_list
{
    char                    *data;
    struct s_linked_list    *next;
}                           linked_list;

char						*add(char *s1, char *s2);
char						*base(char *charset, char *decimal);

char		    			**closest_whole_num(char *divisor, char *minuend);
int             			div_handle_negs(char **dividend, char **divisor, char **sign);
char						*divide(char *dividend, char *divisor);

char						*evaluate_expr(char *exp);
char						*handle_expression(char **expression, char *sign);
char						*traverse_parenthetical(char **expression);
char						push_operator(char **expression);
char						*ft_atoi_str(const char *str);

char            			*get_decimal(char *charset, char *string);

int							get_index(char *array, char c);;
int							get_rightmost_digit(char *str);

char						*initialize_characters(int length, char c);
char						*initialize_zero(int length);
int							is_negative(char *str1);
int							is_str1_smaller(char *str1, char *str2);
void						add_link(linked_list **list, char *str);
linked_list					*create_link(char *str);
char						*get_closest_base(linked_list *list, char *value, int *index);
void						prepend_link(linked_list **list, char *str);
void						print_linked_list(linked_list *list);
int							size(linked_list *list);
char						*summate_linked_list(linked_list *list);
char						*value(linked_list *list, int n);
char						*modulo(char *dividend, char *divisor);

char						*multiply(char *str1, char *str2);

int							number_cmp(char *str1, char *str2);
char						*pad_left(char *s1, int n);
char						*pad_right(char *str, int number_of_zeros);
int							pop_digit(char *str);

char						*power(char *number, char *exponent);
char						*replace(char *input, char *replaced, char *replacerint, int repeat);

char						*stringerize(char c);
char						*subtract(char *s1, char *s2);

void						truncate_zeros(char **str);
void						shift_right(char **string_pointer);
void						swap(char **str1, char **str2);
char						*translate_to_decimal(char *charset, char *expression);
int							zeroed(char *str);
char						*value(linked_list *list, int n);
int							zeroed_character(char *str, char c);
char						*substring(char *str, int i, int j);

void						unit_test();
int does_exist(char *str, char c);
int check_operators(char *exp);
int check_operands(char *exp, char *base);
int check_size(char *exp, char *size);
int validate(char *exp,char *base, char *size);
#endif
