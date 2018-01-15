/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 22:58:23 by lilam             #+#    #+#             */
/*   Updated: 2018/01/15 06:54:25 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"
#define VARS char *sign="1"; char current[2]; char *val=ft_strnew(0); char *tmp;

char	*ft_atoi_str(const char *str)
{
	VARS;
	while (DL(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = "-1";
		str++;
	}
	if (DL(*str) || (*str >= 0 && *str <= 31))
		return ("0");
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			current[0] = *str;
			tmp = val;
			val = ft_strjoin(tmp, current);
			free(tmp);
			str++;
		}
		else
			break ;
	}
	return (multiply(val, sign));
}

char	push_operator(char **expression)
{
	char operator;

	operator = '\0';
	while (**expression == ' ')
		(*expression)++;
	if (**expression == '%')
		operator = **expression;
	if (**expression == '*')
		operator = **expression;
	if (**expression == '/')
		operator = **expression;
	if (**expression == '+')
		operator = **expression;
	if (**expression == '-')
		operator = **expression;
	if (operator)
		(*expression)++;
	return (operator);
}

char	*traverse_parenthetical(char **expression)
{
	char *result;

	while (**expression == ' ')
		(*expression)++;
	if (**expression == '(')
	{
		(*expression)++;
		result = handle_expression(expression, "1");
		while (**expression == ' ')
			(*expression)++;
		(*expression)++;
	}
	else
	{
		result = ft_atoi_str(*expression);
		if (**expression == '+' || **expression == '-')
			(*expression)++;
		while ('0' <= **expression && **expression <= '9')
			(*expression)++;
	}
	return (result);
}

char	*handle_expression(char **expression, char *sign)
{
	char *operand_a;
	char *operand_b;
	char operator;

	operand_a = multiply(sign, traverse_parenthetical(expression));
	operator = push_operator(expression);
	while (operator == '%' || operator == '*' || operator == '/')
	{
		operand_b = traverse_parenthetical(expression);
		if (operator == '%')
			operand_a = modulo(operand_a, operand_b);
		else if (operator == '*')
			operand_a = multiply(operand_a, operand_b);
		else if (operator == '/')
			operand_a = divide(operand_a, operand_b);
		operator = push_operator(expression);
	}
	if (operator == '+')
		return (add(operand_a, handle_expression(expression, "1")));
	else if (operator == '-')
		return (add(operand_a, handle_expression(expression, "-1")));
	return (operand_a);
}

char	*evaluate_expr(char *exp)
{
	exp = replace(exp, "--", "+", 1);
	exp = replace(exp, "+(", "+1*(", 1);
	exp = replace(exp, "-(", "-1*(", 1);
	return (handle_expression(&exp, "1"));
}
