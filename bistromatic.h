/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bistromatic.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroshiusui <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 18:41:07 by hiroshius         #+#    #+#             */
/*   Updated: 2018/01/10 14:29:24 by hiroshius        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BISTROMATIC_H
# define BISTROMATIC_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct		s_list
{
	char			*data;
	int				level;
	struct s_list	*next;
}					t_list;

typedef struct              s_linked_list
{
    char                    *data;
    struct s_linked_list    *next;
}                           linked_list;

char *add(char *s1, char *s2);
char *subtract(char *s1, char *s2);
void truncate_zeros(char **str);

char *ft_itoa(int n);
char *ft_strcpy(char *dst, char *src);
char *ft_strdup(char *s1);
char *ft_strnew(int size);
int ft_strlen(char *str);
void ft_memdel(void **ap);
#endif
