/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husui <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 12:51:13 by husui             #+#    #+#             */
/*   Updated: 2017/11/12 20:55:30 by husui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

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

int		traverse_parenthetical(char **expression)
{
	int result;

	while (**expression == ' ')
		(*expression)++;
	if (**expression == '(')
	{
		(*expression)++;
		result = handle_expression(expression, 1);
		while (**expression == ' ')
			(*expression)++;
		(*expression)++;
	}
	else
	{
		result = ft_atoi(*expression);
		if (**expression == '+' || **expression == '-')
			(*expression)++;
		while ('0' <= **expression && **expression <= '9')
			(*expression)++;
	}
	return (result);
}

int		handle_expression(char **expression, int sign)
{
	int		operand_a;
	int		operand_b;
	char	operator;

	operand_a = sign * traverse_parenthetical(expression);
	operator = push_operator(expression);
	while (operator == '%' || operator == '*' || operator == '/')
	{
		operand_b = traverse_parenthetical(expression);
		if (operator == '%')
			operand_a %= operand_b;
		else if (operator == '*')
			operand_a *= operand_b;
		else if (operator == '/')
			operand_a /= operand_b;
		operator = push_operator(expression);
	}
	if (operator == '+')
		return (operand_a + handle_expression(expression, 1));
	else if (operator == '-')
		return (operand_a + handle_expression(expression, -1));
	return (operand_a);
}

int		evaluate_expr(char *exp)
{
	return (handle_expression(&exp, 1));
}

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(evaluate_expr(av[1]));
		ft_putchar('\n');
	}
	return (0);
}
