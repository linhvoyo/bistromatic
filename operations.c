/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 07:58:23 by lilam             #+#    #+#             */
/*   Updated: 2018/01/09 12:06:15 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

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

void    ft_memdel(void **ap)
{
	if (ap)
	{
		free(*ap);
		*ap = NULL;
	}
}

char *padding(char *s1, int n)
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

void truncate_zeros(char **str)
{
	int i;
	char *temp;

	i = 0;
	while ((*str)[i] && (*str)[i] == '0')
		i++;
	temp = *str;
	*str = ft_strdup(*str + i);
	free(temp);
}

char *addition(char *s1, char *s2)
{
	char *total;

	int len1;
	int len2;
	int carry;
	int i;

	carry = 0;
	if ((len1 = ft_strlen(s1) + 1) > (len2 = ft_strlen(s2) + 1))
	{
		s2 = padding(s2,len1 - 1);
		total = (char *)malloc(sizeof(char) * (len1 + 1));
		i = len1;
	}
	else
	{
		total = (char *)malloc(sizeof(char) * (len2 + 1));
		s1 = padding(s1, len2 - 1);
		i = len2;
	}
	if (!total)
		return (NULL);

	total[i--] = '\0';
	while (i > 0)
	{
		int value1 = s1[i - 1] - '0';
		int value2 = s2[i - 1] - '0';
		if ((value1) + (value2) > 9)
		{
			total[i] = ((value1) + (value2)) % 10 + carry + '0';
			carry = 1;
			if (i == 1)
				total[0] = '1';
		}
		else
		{
			total[i] = (value1) + (value2) + carry + '0';
			carry = 0;
			if (i == 1)
				total[0] = '0';
		}
		i--;
	}
	truncate_zeros(&total);
	return (total);	
}

char *subtraction(char *s1, char *s2)
{
	char *total;

	int len1;
	int len2;
	int carry;
	int small;

	int big;

	big = 0;
	carry = 0;
	if ((len1 = ft_strlen(s1)) > (len2 = ft_strlen(s2)))
	{
		big = len1;
		small = len2;
		total = (char *)malloc(sizeof(char) * (len1 + 1));
		s2 = padding(s2,len1);
	}
	else
	{
		big = len2;
		small = len1;
		total = (char *)malloc(sizeof(char) * (len2 + 1));
		s1 = padding(s1,len2);
	}
	if (!total)
		return (NULL);
	
	printf("%d\n", big);
	printf("%d\n", small);

/*	
	total[i--] = '\0';
	while (i > 0)
	{
		int value1 = s1[i - 1] - '0';
		int value2 = s2[i - 1] - '0';
		if ((value1) - (value2) < 0)
		{
			total[i] = (value1 + 10) - (value2) + carry + '0';
			carry = -1;
		}
		else
		{
			total[i] = (value1) - (value2) + carry + '0';
			carry = 0;
		}
		i--;
	}

*/
	return ("sdfs");	
}

/*
char *multiplication(char *s1, char *s2)
{
	char *total;
	int i;

	i = 0;
	total = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	total[i--] = '\0';
}

*/

int main()
{
//	printf("%s\n", addition("15", "80"));
	printf("%s\n", subtraction("5", "10"));
//	printf("%s\n", multiplication("15", "80"));
//	addition("5654654", "32132564154");
	return (0);
}
