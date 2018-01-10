/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bistromatic.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroshiusui <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 18:41:07 by hiroshius         #+#    #+#             */
/*   Updated: 2018/01/10 15:53:06 by hiroshius        ###   ########.fr       */
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

#endif
