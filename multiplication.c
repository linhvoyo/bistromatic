/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiplication.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroshiusui <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 09:25:16 by hiroshius         #+#    #+#             */
/*   Updated: 2018/01/10 12:10:46 by hiroshius        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "bistromatic.h"

linked_list	*create_link(char *str)
{
	linked_list	*new;

	new = (linked_list *)malloc(sizeof(linked_list));
	new->data = str;
	new->next = 0;
	return (new);
}

void	print_linked_list(linked_list *list)
{
	while (list)
	{
		printf("%s\n", list->data);
		list = list->next;
	}
}

char	*summate_linked_list(linked_list *list)
{

}

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

/*
**	zeroed
**	2018-01-10 11-26-31
**	Works.
**	"0005" --> 0
**	"0000" --> 1
*/

int zeroed(char *str)
{
	while (*str)
	{
		if (*str != '0')
			return (0);
		str++;
	}
	return (1);
}

/*
**	get_rightmost_digit
**	2018-01-10 11-25-48	
**	Works.
**	555 --> 5
**	554 --> 4
**	5 --> 5
**	0 --> 0
**	"<Empty string>" --> 0
*/

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

/*
**	shift_right
**	2018-01-10 11-25-48
**	Works.
**	Takes in the memory location for an array of characters, and shifts the
**	digits right.
**	500 --> 050
**	050 --> 005
**	005 --> 000
*/

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

/*
**	pop_digit
**	2018-01-10 11:37 Tested
**	Gets the one's place digit,
**	Pops the number off of the string.
*/

int pop_digit(char *str)
{
	int value;

	value = get_rightmost_digit(str);
	shift_right(&str);
	return (value);
}

/*
char *multiply(char *str1, char *str2)
{
	char *new;
}
*/

int main()
{
	char *str1;
	str1 = malloc(sizeof(char) * 8);
	str1[0] = '0';
	str1[1] = '0';
	str1[2] = '5';
	str1[3] = '4';
	str1[4] = '3';
	str1[5] = '2';
	str1[6] = '1';
	str1[7] = '\0';

	char *str2;
	str2 = malloc(sizeof(char) * 8);
	str2[0] = '0';
	str2[1] = '0';
	str2[2] = '1';
	str2[3] = '2';
	str2[4] = '3';
	str2[5] = '4';
	str2[6] = '5';
	str2[7] = '\0';

	linked_list *new;
	new = create_link(ft_strdup(str1));
	print_linked_list(new);
}
