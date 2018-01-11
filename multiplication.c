/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiplication.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroshiusui <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 19:07:21 by hiroshius         #+#    #+#             */
/*   Updated: 2018/01/10 19:31:35 by hiroshius        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

linked_list	*create_link(char *str)
{
	linked_list	*new;

	new = (linked_list *)malloc(sizeof(linked_list));
	new->data = str;
	new->next = 0;
	return (new);
}

void add_link(linked_list **list, char *str)
{
	linked_list *iter;

	iter = (*list);
	while (iter->next)
   		iter = iter->next;
	iter->next = create_link(str);
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
	char *sum;

	if (list && !list->next)
		return (list->data);
	else if (!list)
		return ("0");
	sum = 0;
	while (list)
	{
		if (!sum)
			sum = add("0", list->data);
		else
			sum = add(sum, list->data);
		list = list->next;
	}
	return (sum);
}

char	*pad_right(char *str, int number_of_zeros)
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

int pop_digit(char *str)
{
	int value;

	value = get_rightmost_digit(str);
	shift_right(&str);
	return (value);
}

void initialize_zero(char *str, int length)
{
	int i;

	i = 0;
	while (i < length)
		str[i++] = '0';
	str[i] = '\0';
}

char *multiply_helper(char *str1, char *str2)
{
	char *row;
	int i;
	int j;
	int value;
	int carry;
	int length;
	int singles_digit;

	i = ft_strlen(str1);
	j = ft_strlen(str2);
	row = ft_strnew(i + j);
	initialize_zero(row, i + j);
	length = ft_strlen(row) - 1;
	while (i)
	{
		j = ft_strlen(str2);
		while (j)
		{
			value = (str1[i - 1] - '0') * (str2[j - 1] - '0');
			carry = value / 10;
			singles_digit = value % 10 + row[i] - '0';
			if (singles_digit > 9)
			{
				carry = carry + singles_digit / 10;
				singles_digit = singles_digit % 10;
			}
			row[i] = singles_digit + '0';
			row[i - 1] = carry + row[i - 1];
			j--;
		}
		length--;
		i--;
	}
	return (row);
}

char *multiply(char *str1, char *str2)
{
	linked_list *list;
	linked_list *iter;
	char *negative_flag;
	int count;

	count = 0;
	list = 0;
	if ((str1[0] == '-' && str2[0] != '-') || (str1[0] != '-' && str2[0] == '-'))
	{
		negative_flag = "-";
		if (str1[0] == '-')
			str1++;
		if (str2[0] == '-')
			str2++;
	}
	else
	{
		negative_flag = "";
		if (str1[0] == '-')
			str1++;
		if (str2[0] == '-')
			str2++;
	}
	while (!zeroed(str2))
	{
		if (!list)
			list = create_link(multiply_helper(str1, pad_right(ft_itoa(pop_digit(str2)), count)));
		else
			add_link(&list, multiply_helper(str1, pad_right(ft_itoa(pop_digit(str2)), count)));
		count++;
	}
	return (ft_strjoin(negative_flag, summate_linked_list(list)));
}

/*
int main()
{
	char *str1;
	str1 = malloc(sizeof(char) * 6);
	str1[0] = '-';
	str1[1] = '5';
	str1[2] = '1';
	str1[3] = '1';
	str1[4] = '\0';

	char *str2;
	str2 = malloc(sizeof(char) * 6);
	str2[0] = '-';
	str2[1] = '2';
	str2[2] = '3';
	str2[3] = '4';
	str2[4] = '5';
	str2[5] = '\0';

	char *str3;
	str3 = malloc(sizeof(char) * 5);
	str3[0] = '1';
	str3[1] = '2';
	str3[2] = '3';
	str3[3] = '0';
	str3[4] = '\0';

	linked_list *new1;
	new1 = create_link(ft_strdup(str1));

	linked_list *new2;
	new2 = create_link(ft_strdup(str2));
	new1->next = new2;

	linked_list *new3;
	new3 = create_link(ft_strdup(str3));
	new2->next = new3;
	// -511 * -2345 = 
	printf("%s\n", multiply(str1, str2));
}
*/
