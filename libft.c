/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroshiusui <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 12:30:45 by hiroshius         #+#    #+#             */
/*   Updated: 2018/01/10 13:25:56 by hiroshius        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char    *ft_strdup(char *s1)
{
    char    *temp;
    int        i;

    temp = (char*)malloc(sizeof(*temp) * (ft_strlen(s1) + 1));
    i = -1;
    if (temp)
    {
        while (s1[++i])
            temp[i] = s1[i];
        temp[i] = '\0';
    }
    return (temp);
}

char	*ft_strnew(int size)
{
	int		i;
	char	*new;

	i = 0;
	new = (char *)malloc(size + 1);
	if (new == NULL)
		return (NULL);
	while (i != size)
	{
		new[i] = '\0';
		i++;
	}
	new[i] = '\0';
	return (new);
}

void    ft_memdel(void **ap)
{
    if (ap)
    {
        free(*ap);
        *ap = NULL;
    }
}

char	*ft_strcpy(char *dst, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = src[i];
	return (dst);
}
