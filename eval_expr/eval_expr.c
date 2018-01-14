/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husui <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 12:51:13 by husui             #+#    #+#             */
/*   Updated: 2018/01/13 17:38:49 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "util.h"
#include <stdio.h>

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
//		printf("result_2: %d\n", result);
		while (**expression == ' ')
			(*expression)++;
		(*expression)++;
	}
	else
	{
		result = ft_atoi(*expression);
//		printf("expression %s \n",*expression);
		//printf("result_3: %d\n", result);
		if (**expression == '+' || **expression == '-')
			(*expression)++;
		while ('0' <= **expression && **expression <= '9')
			(*expression)++;
	}
//	printf("result: %d\n", result);
	return (result);
}

int		handle_expression(char **expression, int sign)
{
	int		operand_a;
	int		operand_b;
	char	operator;

	operand_a = sign * traverse_parenthetical(expression);
//	printf("operand_a: %d\n", operand_a);
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
//	puts(exp);
	if (exp[0] == '-' && exp[1] == '(')
	{
		exp++;
		return (handle_expression(&exp, -1));
	}
	return (handle_expression(&exp, 1));
}

int		main()
{
//	ft_putnbr(evaluate_expr("398 + 505 / 505 + 8 * (5 + 10) % 10"));
//	ft_putchar('\n');
	ft_putnbr(evaluate_expr("-(12-(4*32))"));
	ft_putchar('\n');
//	ft_putnbr(evaluate_expr("-12-(4*32)"));
//	ft_putchar('\n');
//	ft_putnbr(evaluate_expr("(12-(4*32))"));
//	ft_putchar('\n');
	ft_putnbr(evaluate_expr("(12*(13+15/5*(6/(12+14%(30%5+(10*25)-46)+16)-20)/43)*20)*((12-98*42)*(16+63-50/3))"));
	return (0);
}
