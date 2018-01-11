/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_zero.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroshiusui <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 19:54:09 by hiroshius         #+#    #+#             */
/*   Updated: 2018/01/10 20:01:39 by hiroshius        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

void initialize_zero(char *str, int length)
{
    int i;

    i = 0;
    while (i < length)
        str[i++] = '0';
    str[i] = '\0';
}
