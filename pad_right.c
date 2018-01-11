/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_right.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroshiusui <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 20:02:21 by hiroshius         #+#    #+#             */
/*   Updated: 2018/01/10 20:02:29 by hiroshius        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

char    *pad_right(char *str, int number_of_zeros)
{
    char *new;
    int length;

    if (!number_of_zeros)
        return (str);
    length = ft_strlen(str);
    new = ft_strnew(length + number_of_zeros);
    new = ft_strcpy(new, str);
    while (number_of_zeros)
        new[(length - 1) + number_of_zeros--] = '0';
    return (new);
}
