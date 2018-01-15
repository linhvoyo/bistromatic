#include "bistromatic.h"

int does_exist(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int check_operators(char *exp)
{
	char *operators;
	int i;
	int open;
	int close;

	operators = strdup("()+-*/%");

	i = 0;
	open = 0;
	close = 0;
	while (exp[i])
	{
		if (exp[i] == '(')
			open++;
		else if (exp[i] == ')')
			close++;
		if (exp[i] == '(' && i != 0)
			if (!(does_exist(operators, exp[i-1])))
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
	puts("operators correct");	
	return (1);
}

int check_operands(char *exp,char *base)
{
	char *valid_input;
	int i;
	int j;

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
	puts("operands correct");
	return (1);
}

int check_size(char *exp, char *size)
{
	if ((int)ft_strlen(exp) != ft_atoi(size))
		return (0);
	puts("size correct");
	return (1);
}

int validate(char *exp, char *base, char *size)
{
	if (!check_size(exp, size))
		return (0);
	if (!check_operands(exp, base))
		return (0);
	if (!check_operators(exp))
		return (0);
	return (1);
}
