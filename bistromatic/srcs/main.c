/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 08:07:04 by lilam             #+#    #+#             */
/*   Updated: 2018/01/15 09:27:21 by hiroshius        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"
#define VARS char buf[100 + 1]; int ret; char *exp=ft_strnew(0); char *tmp;
#define READ buf[ret]='\0'; tmp=exp; exp=ft_strjoin(tmp, buf);free(tmp);
#define TRANSLATE evaluate_expr(translate_to_decimal(argv[1], exp))
#define VARS2 VARS; tmp = ft_strnew(0);

int	main(int argc, char **argv)
{
	VARS2;
	if (argc != 3)
	{
		ft_putstr("syntax error");
		return (-1);
	}
	while ((ret = read(0, buf, 100)))
	{
		READ;
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
		if (!ft_strcmp("0123456789", argv[1]))
			ft_putstr(evaluate_expr(exp));
		else
			ft_putstr(base(argv[1], TRANSLATE));
	}
	return (0);
}
