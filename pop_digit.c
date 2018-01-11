/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_digit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroshiusui <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 19:54:48 by hiroshius         #+#    #+#             */
/*   Updated: 2018/01/10 20:01:30 by hiroshius        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

int pop_digit(char *str)
{
    int value;

    value = get_rightmost_digit(str);
    shift_right(&str);
    return (value);
}
