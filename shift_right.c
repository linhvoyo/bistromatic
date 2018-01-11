/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_rice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroshiusui <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 20:00:21 by hiroshius         #+#    #+#             */
/*   Updated: 2018/01/10 20:01:11 by hiroshius        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

void shift_right(char **string_pointer)
{
    int alternate;
    int i;
    char *str;
    char temp;
    char temp2;

    str = *string_pointer;
    i = 0;
    while (str[i] && str[i] == '0')
        i++;
    if (!str[i])
        return ;
    temp = 0;
    temp2 = 0;
    alternate = 0;
    while (str[i])
    {
        if (!temp2)
        {
            temp = str[i];
            temp2 = str[i + 1];
            str[i] = '0';
        }
        else
        {
            if (!alternate)
            {
                str[i] = temp;
                temp = str[i + 1];
                alternate = 1;
            }
            else if (alternate)
            {
                str[i] = temp2;
                temp2 = str[i + 1];
                alternate = 0;
            }
        }
        i++;
    }
}
