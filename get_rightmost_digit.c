/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rightmost_digit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroshiusui <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 19:59:12 by hiroshius         #+#    #+#             */
/*   Updated: 2018/01/10 20:01:19 by hiroshius        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

int get_rightmost_digit(char *str)
{
    int i;

    i = 0;
    if (!str[i])
        return (0);
    if (!str[i + 1])
        return (str[i] - '0');
    while (str[i + 1])
        i++;
    return (str[i] - '0');
}
