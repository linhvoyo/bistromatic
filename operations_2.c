/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 07:58:23 by lilam             #+#    #+#             */
/*   Updated: 2018/01/11 10:33:51 by hiroshius        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

char	**closest_whole_num(char *divisor, char *minuend)
{
	char **res;
	char *total;
	char *tmp;
	char counter[2];
	int i;

	res = (char **)malloc(sizeof(char*) * 2);
	i = 0;
	total = divisor;
	while (ft_strncmp((tmp = pad_left(minuend, ft_strlen(total))), total, ft_strlen(minuend)) >= 0)
	{
		free(tmp);
		total = add(total, divisor);
		i++;
	}
	counter[0] = '0' + i;
	res[0] = ft_strdup(counter);
	res[1] = subtract(total, divisor);
	return(res);
}

char *divide(char *dividend, char *divisor)
{
	char *total;
	char *minuend;
	char *tmp;
	char div[2];
	char **res;

	int start_len;
	int i;
	int j;

	j = 0;
	start_len = ft_strlen(divisor);
	if (ft_strncmp(dividend, divisor, start_len) < 0 )
		start_len = start_len + 1;
	total = (char *)malloc(sizeof(char) * (ft_strlen(dividend) - start_len + 1 + 1));

	if (!total)
		return (NULL);
	i = start_len;

	minuend = ft_strdup(dividend);
	minuend[start_len] = '\0';
	res = closest_whole_num(divisor, minuend);
	total[j++] = res[0][0];
	printf("total[%d] %c\n", j - 1, total[j - 1]);

	while (dividend[i])
	{
		printf("\n\n%c\n", dividend[i]);
		tmp = minuend;
		div[0] = dividend[i];
		puts(minuend);
		if (res[0][0] > 0)
			minuend = ft_strjoin(subtract(minuend,divisor), div);
		else
			minuend = ft_strjoin(minuend, div);
		puts(minuend);
		free(res);
	//	res = closest_whole_num(divisor, minuend);
		total[j] = res[0][0];
		printf("total[%d] %c\n", j, total[j]);
		res = closest_whole_num(divisor, minuend);
		j++;	
		free(tmp);
		i++;
	}

	puts(total);
	return ("\n\ntest");
}

/*
int main()
{
	char **res;
	res = closest_whole_num("7", "6");
//	res = closest_whole_num("8", "9");
	
//	res[0] = "hi";
	puts(res[0]);
	puts(res[1]);

	printf("%s\n", add("369", "3690"));
	printf("%s\n", add("15", "80"));
	printf("%s\n", add("5654654", "32132564154"));
	printf("%s\n", divide("56756734", "558"));
	printf("%s\n", subtract("567", "558"));

	printf("%s\n", subtract("5", "10"));
	printf("%s\n", subtract("10", "5"));
	printf("%s\n", subtract("644", "1000090"));
	printf("%s\n", subtract("1000090", "644"));
	printf("%s\n", add("15", "80"));
	printf("%s\n", subtract("3000546090", "3000546089"));
	printf("%s\n", subtract("20001230090", "600450344"));
	printf("%s\n", subtract("600450344", "20001230090"));
//	printf("%s\n", multiplication("15", "80"));
	printf("%s\n", add("5654654", "32132564154"));

	return (0);
}
*/
