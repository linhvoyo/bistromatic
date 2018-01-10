/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiplication.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroshiusui <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 09:25:16 by hiroshius         #+#    #+#             */
/*   Updated: 2018/01/10 11:28:42 by hiroshius        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/*	zeroed
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

/*	get_rightmost_digit
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

/*	shift_right
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
char *multiply(char *str1, char *str2)
{
	char *new;
}
*/

int main()
{
	char *str;
	str = malloc(sizeof(char) * 8);
	str[0] = '0';
	str[1] = '6';
	str[2] = '5';
	str[3] = '4';
	str[4] = '3';
	str[5] = '0';
	str[6] = '0';
	str[7] = '\0';
	shift_right(&str);
	printf("%d\n", get_rightmost_digit(""));
}
