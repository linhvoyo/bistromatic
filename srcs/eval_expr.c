#include "../includes/bistromatic.h"

char *ft_atoi_str(const char *str)
{
	char *sign;
	char current[2];
	char *val;
	char *tmp;

	sign = "1";
	val = ft_strnew(0);
	while (DL(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = "-1";
		str++;;
	}
	if (DL(*str) || (*str >= 0 && *str <= 31))
		return ("0");;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			current[0] = *str;
			tmp = val;
			val = ft_strjoin(val, current);
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

	while(**expression == ' ')
		(*expression)++;
	if (**expression == '(')
	{
		(*expression)++;
		result = handle_expression(expression, "1");
//		printf("result_2: %s\n", result);
		while (**expression == ' ')
				(*expression)++;
		(*expression)++;
	}
	else
	{
		result = ft_atoi_str(*expression);
//		printf("result_3: %s\n", result);
		if (**expression == '+' || **expression == '-')
			(*expression)++;
		while ('0' <= **expression && **expression <= '9')
			(*expression)++;
	}
//	printf("result: %s\n", result);
	return (result);
}


char	*handle_expression(char **expression, char *sign)
{
	char *operand_a;
	char *operand_b;	
	char operator;

	operand_a = multiply(sign, traverse_parenthetical(expression));
//	printf("operand_a: %s\n", operand_a);
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
		return (add(operand_a,handle_expression(expression, "1")));
	else if (operator == '-')
		return (add(operand_a,handle_expression(expression, "-1")));
	return (operand_a);
}

char *evaluate_expr(char *exp)
{
//	puts(exp);
//	printf("%s\n", handle_expression(&exp, "1"));
	exp = replace(exp, "--", "+", 1);
	exp = replace(exp, "+(", "+1*(", 1);
	exp = replace(exp, "-(", "-1*(", 1);
	/*
	if (exp[0] == '-' && exp[1] == '(')
	{
		exp++;
		return (handle_expression(&exp, "-1"));
	}
	*/
	return (handle_expression(&exp, "1"));
}
