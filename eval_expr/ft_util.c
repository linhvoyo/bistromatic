/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husui <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 12:55:02 by husui             #+#    #+#             */
/*   Updated: 2017/11/12 16:42:41 by husui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_atoi(char *str)
{
	int sign;
	int result;

	result = 0;
	while (('\t' <= *str && *str <= '\r') || (*str == ' '))
		str++;
	sign = (*str == '-') * -2 + 1;
	if (*str == '-' || *str == '+')
		str++;
	while ('0' <= *str && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (sign * result);
}

void	ft_putnbr_helper(int n)
{
	if (n > 9)
	{
		ft_putnbr_helper(n / 10);
		ft_putnbr_helper(n % 10);
	}
	else
		ft_putchar(n + '0');
}

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	ft_putnbr_helper(n);
}
