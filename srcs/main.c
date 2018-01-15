#include "bistromatic.h"
#include <stdio.h>
#define BUFF_SIZE 2

int main(int argc, char **argv)
{
	//unit_test();
	char buf[BUFF_SIZE + 1];
	int ret;
	char *exp;
	char *tmp;

	exp = ft_strnew(0);
	tmp = ft_strnew(0);
	if (argc != 3)
	{
		ft_putstr("syntax error");
		return (-1);
	}
	while ((ret = read(0, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		exp = ft_strjoin(tmp = exp, buf);
		free(tmp);
	}
	if (exp[ft_strlen(exp) - 1] == '\n')
		exp[ft_strlen(exp) - 1] = '\0';
	if (!(validate(exp, argv[1], argv[2])))
	{
		ft_putstr("syntax error");
		return (-1);
	}
	else
	{
		puts(exp);
		ft_putstr(base(argv[1], evaluate_expr(translate_to_decimal(argv[1], exp))));
	}
	close(0);
//	ft_putchar('\n');
	return (0);
}
