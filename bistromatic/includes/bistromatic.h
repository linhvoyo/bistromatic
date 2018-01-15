#ifndef BISTROMATIC_H
# define BISTROMATIC_H
# include "../libft/includes/libft.h"
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
char *initialize_zero(int length);
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
char *modulo(char *dividend, char *divisor);
int is_negative(char *str1);
void swap(char **str1, char **str2);
void prepend_link(linked_list **list, char *str);
char *base(char *charset, char *decimal);
char *value(linked_list *list, int n);
int size(linked_list *list);
char *get_closest_base(linked_list *list, char *value, int *index);
char *initialize_characters(int length, char c);
int zeroed_character(char *str, char c);
int get_index(char *array, char c);
char *power(char *number, char *exponent);
char *get_decimal(char *charset, char *string);
char *stringerize(char c);
char *substring(char *str, int i, int j);
char *replace(char *input, char *replaced, char *replacer, int repeat);
char *translate_to_decimal(char *charset, char *expression);

char push_operator(char **expression);
char *traverse_parenthical(char **expression);
char *handle_expression(char **expression, char *sign);
char *evaluate_expr(char *exp);
char *ft_atoi_str(const char *str);

void unit_test();
int validate(char *exp,char *base, char *size);
#endif
