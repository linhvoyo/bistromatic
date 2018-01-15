#include "bistromatic.h"
#include <stdio.h>
#define BUFF_SIZE 2

//int validate(char *exp,char *base, char *size);

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
		ft_putstr("syntax error\n");
		return (-1);
	}
	while ((ret = read(0, buf, BUFF_SIZE)))
	{
		printf("%d\n", ret);
		buf[ret] = '\0';
		tmp = exp;
		exp = ft_strjoin(tmp, buf);
		free(tmp);
	}
	exp[ft_strlen(exp) - 1] = '\0';
	if (!(validate(exp, argv[1], argv[2])))
	{
		ft_putstr("syntax error\n");
		return (-1);
	}
	else
	{
		puts(exp);
		ft_putstr(evaluate_expr(exp));
	}
	close(0);
	ft_putchar('\n');
	return (0);
}
