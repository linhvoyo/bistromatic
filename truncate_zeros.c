/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   truncate_zeros.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroshiusui <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 09:56:51 by hiroshius         #+#    #+#             */
/*   Updated: 2018/01/11 11:20:45 by hiroshius        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

void truncate_zeros(char **str)
{
    int i;
    int sign;

    char *temp;

    i = 0;
    if (*str[i] == '-')
    {
        sign = -1;
        i++;
    }
    while ((*str)[i] && (*str)[i] == '0')
        i++;
    temp = *str;
    if (sign == -1)
        *str = ft_strjoin("-", *str + i);
    else
        *str = ft_strdup(*str + i);
    free(temp);
}
