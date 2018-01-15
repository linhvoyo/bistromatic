/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 08:30:06 by lilam             #+#    #+#             */
/*   Updated: 2018/01/15 09:08:32 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"
#define VARS char *operators; int i = 0; int open = 0; int close = 0;

int	does_exist(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int	check_operators(char *exp)
{
	VARS;
	operators = strdup("()+-*/%");
	while (exp[i])
	{
		if (exp[i] == '(')
			open++;
		else if (exp[i] == ')')
			close++;
		if (exp[i] == '(' && i != 0)
			if (!(does_exist(operators, exp[i - 1])))
				return (0);
		if (exp[i] == '*' && exp[i + 1] == '*')
			return (0);
		if (exp[i] == '/' && exp[i + 1] == '/')
			return (0);
		if (exp[i] == '%' && exp[i + 1] == '%')
			return (0);
		i++;
	}
	if (close != open)
		return (0);
	return (1);
}

int	check_operands(char *exp, char *base)
{
	char	*valid_input;
	int		i;
	int		j;

	valid_input = ft_strjoin(base, "()+-*/%");
	while (*exp)
	{
		i = 0;
		j = 0;
		while (valid_input[i])
		{
			if (*exp == valid_input[i])
				j++;
			i++;
		}
		if (j == 0)
			return (0);
		exp++;
	}
	return (1);
}

int	check_size(char *exp, char *size)
{
	if ((int)ft_strlen(exp) > ft_atoi(size))
		return (0);
	return (1);
}

int	validate(char *exp, char *base, char *size)
{
	if (!check_size(exp, size))
		return (0);
	if (!check_operands(exp, base))
		return (0);
	if (!check_operators(exp))
		return (0);
	return (1);
}
