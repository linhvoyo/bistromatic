/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_left.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroshiusui <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 09:55:38 by hiroshius         #+#    #+#             */
/*   Updated: 2018/01/11 09:56:00 by hiroshius        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

char *pad_left(char *s1, int n)
{
    char *str;
    int len;
    int i;
    int j;

    len = ft_strlen(s1);
    str = (char*)malloc(sizeof(char)*(n + 1));
    if (!str)
        return (0);
    i = 0;
    j = 0;
    while (i < (n - len))
        str[i++] = '0';
    while (i < n)
        str[i++] = s1[j++];
    str[n] = '\0';
    return (str);
}
