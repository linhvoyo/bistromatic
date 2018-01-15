/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 08:07:04 by lilam             #+#    #+#             */
/*   Updated: 2018/01/15 08:36:45 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"
#define VARS char buf[100 + 1]; int ret; char *exp=ft_strnew(0); char *tmp;

int	main(int argc, char **argv)
{
	unit_test();
	VARS;
	tmp = ft_strnew(0);
	if (argc != 3)
	{
		ft_putstr("syntax error");
		return (-1);
	}
	while ((ret = read(0, buf, 100)))
	{
		buf[ret] = '\0';
		tmp = exp;
		exp = ft_strjoin(tmp, buf);
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
		ft_putstr(evaluate_expr(exp));
//		ft_putstr(base(argv[1], evaluate_expr(translate_to_decimal(argv[1], exp))));
	}
	close(0);
	return (0);
}
