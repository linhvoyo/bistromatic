#include "bistromatic.h"

char *pad_left(char *s1, int n)
{
	char *str;
	int len;
	int i;
	int j;

	len = ft_strlen(s1);
	str = (char*)malloc(sizeof(char)*(n + 1));
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (i < (n - len))
		str[i++] = '0';
	while (i < n)
		str[i++] = s1[j++];
	str[n] = '\0';
	return (str);
}

void truncate_zeros(char **str)
{
	int i;
	int sign;

	char *temp;

	i = 0;
	if (*str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while ((*str)[i] && (*str)[i] == '0')
		i++;
	temp = *str;
	if (sign == -1)
		*str = ft_strjoin("-", *str + i);
	else
		*str = ft_strdup(*str + i);
	free(temp);
}



/*
char *add(char *s1, char *s2)
{
	char *total;

	int len1;
	int len2;
	int carry;
	int i;

	carry = 0;
	if ((len1 = ft_strlen(s1) + 1) > (len2 = ft_strlen(s2) + 1))
	{
		s2 = pad_left(s2,len1 - 1);
		total = (char *)malloc(sizeof(char) * (len1 + 1));
		i = len1;
	}
	else
	{
		total = (char *)malloc(sizeof(char) * (len2 + 1));
		s1 = pad_left(s1, len2 - 1);
		i = len2;
	}
	if (!total)
		return (NULL);
	total[i--] = '\0';
	while (i > 0)
	{
		int value1 = s1[i - 1] - '0';
		int value2 = s2[i - 1] - '0';
	//	printf("value1 %d value2 %d\n", value1, value2);
		if ((value1) + (value2) > 9)
		{
			total[i] = ((value1) + (value2)) % 10 + carry + '0';
			carry = 1;
			if (i == 1)
				total[0] = '1';
		}
		else if (value1 + value2 + carry == 10)
		{
			total[i] = '0';
			carry = 1;
		}
		else
		{
			total[i] = (value1) + (value2) + carry + '0';
			carry = 0;
			if (i == 1)
				total[0] = '0';
		}
	//	printf("total[%d] %c \n", i, total[i]); 
		i--;
	}
	truncate_zeros(&total);

	return (total);	
}
*/

int is_str1_smaller(char *str1, char *str2)
{
	int n1;
	int n2;
	int i;
	
	if ((n1 = ft_strlen(str1)) < (n2 = ft_strlen(str2)))
		return (1);
	if (n2 < n1)
		return (0);
	i = 0;
	while (i < n1)
	{
		if (str1[i] < str2[i])
			return (1);
		else if (str1[i] > str2[i])
			return (0);
		i++;
	}
	return (0);
}

char *subtract(char *s1, char *s2)
{
	char *total;
	char *tmp;

	int carry;
	int big;
	int i;
	int sign;

	carry = 0;
	sign = 1;
	big = ft_strlen(s1);
	if (is_str1_smaller(s1, s2) && (big = ft_strlen(s2) + sign))
	{
		total = (char *)malloc(sizeof(char) * (big + 1 + sign));
		tmp = s1;
		s1 = s2;
		s2 = tmp;
		sign = -1;
	}
	else
		total = (char *)malloc(sizeof(char) * (big + 1));
	if (!total)
			return (NULL);
	s1 = pad_left(s1, big);
	s2 = pad_left(s2, big);
	i = big;
	int loop = 0;
	total[i--] = '\0';
	while (i >= 0)
	{
		loop = 0;
		int value1 = s1[i] - '0';
		int value2 = s2[i] - '0';
	//	printf("value 1: %d, value 2: %d\n", value1, value2);
		if ((value1) - (value2) < 0)
		{
			total[i] = (value1 + 10) - (value2) + carry + '0';
			carry = -1;
			loop = 1;
		}
		else if (carry == -1 && value1 - value2 == 0)
		{
	//		puts("here");
	//		printf("value 1: %d, value 2: %d\n", value1, value2);
			total[i] = 10 + carry + '0';
	//		printf("total[i] %c\n", total[i]);
			carry = -1;
			loop = 1;
		}
		else
		{
			total[i] = (value1) - (value2) + carry + '0';
			carry = 0;
			loop = 1;
		}
	//	printf("%c total[%d] \n", total[i], i );
		if (!loop)
			total[i] = '0';
		i--;
	}
	if (sign == -1)
		total[0] = '-';
	if (number_cmp("0", total) == 0)
		return ("0");
	truncate_zeros(&total);
	return (total);	
}

char	**closest_whole_num(char *divisor, char *minuend)
{
	char **res;
	char *total;
	char *tmp;
	char counter[2];
	int i;
	int len;

	res = (char **)malloc(sizeof(char*) * 2);
	i = 0;
	total = divisor;
	if (ft_strlen(divisor) > ft_strlen(minuend))
		len = ft_strlen(divisor);
	else 
		len = ft_strlen(minuend);
	total = pad_left(total, len);
	while (ft_strncmp((tmp = pad_left(minuend, ft_strlen(total))), total, ft_strlen(minuend)) >= 0)
	{
		free(tmp);
		total = add(total, divisor);
		i++;
	}
	counter[0] = '0' + i;
	res[0] = ft_strdup(counter);
	res[1] = subtract(total, divisor);
	if (counter[0] == '0')
		res[1] = ft_strdup(&counter[0]);
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

	start_len = ft_strlen(divisor);
	if (number_cmp(dividend, divisor) < 0)
		return ("0");
	if (ft_strncmp(dividend, divisor, start_len) < 0 )
		start_len = start_len + 1;
	total = (char *)malloc(sizeof(char) * (ft_strlen(dividend) - start_len + 1 + 1));
	if (!total)
		return (NULL);
	i = start_len;
	j = 0;
	minuend = ft_strdup(dividend);
	minuend[start_len] = '\0';
	dividend = (pad_right(dividend, 1));
	while (dividend[i])
	{
		res = closest_whole_num(divisor, minuend);
		tmp = minuend;
		div[0] = dividend[i++];
//		printf("dividend %c | minuend %s | res %s | divisor %s \n", dividend[i], minuend, res[1], divisor);
		minuend = ft_strjoin(subtract(minuend, res[1]), div);
		total[j++] = res[0][0];
		free(res);
		free(tmp);
//		printf("total[%d] %c\n", j, total[j]);
	}
	total[j] = '\0';
	return (total);
}

/*
int main()
{
//
//	char **res;
//	res = closest_whole_num("7", "6");
//	res = closest_whole_num("558", "3987");
//	res = closest_whole_num("8", "9");
//	res = closest_whole_num("558", "95");	
//	res[0] = "hi";
//	puts(res[0]);
//	puts(res[1]);
//	printf("%s\n", add("369", "3690"));
//	printf("%s\n", add("15", "80"));
//	printf("%s\n", add("5654654", "32132564154"));
//	printf("%s\n", divide("10", "5"));
//	printf("%s\n", divide("15", "5"));
//	printf("%s\n", divide("20", "5"));
//	printf("%s\n", divide("21", "5"));
//	printf("%s\n", divide("22", "5"));
//	printf("%s\n", divide("23", "5"));
//	printf("%s\n", divide("24", "5"));
//	printf("%s\n", divide("29", "5"));
//	printf("%s\n", divide("30", "5"));
//	printf("%s\n", divide("35", "5"));
//	printf("%s\n", divide("100", "5"));
//	printf("%s\n", divide("105", "5"));
//	printf("%s\n", divide("106", "5"));
//	printf("%s\n", divide("210", "5"));
//	printf("%s\n", divide("200", "500"));
//	printf("%s\n", divide("567567387899889978", "56545645645658"));
//	printf("%s\n", divide("567567387899889978", "56545645645646666666666666665658"));
//	printf("%s\n", divide("567567387899889978", "9791321321312355646451321897789877894687898789778946156987849164544561231256545645645658"));
//	printf("%s\n", divide("56756734545455789987879797987898789798798798798797987977879879879879878998797897154567987899889978", "56545645645658"));
//	printf("%s\n", subtract("956", "558"));
//	printf("%s\n", subtract("5", "10"));
//	printf("%s\n", subtract("10", "5"));
//	printf("%s\n", subtract("644", "1000090"));
//	printf("%s\n", subtract("1000090", "644"));
//	printf("%s\n", add("15", "80"));
//	printf("%s\n", subtract("3000546090", "3000546089"));
//	printf("%s\n", subtract("20001230090", "600450344"));
//	printf("%s\n", subtract("600450344", "20001230090"));
//	printf("%s\n", multiplication("15", "80"));
//	printf("%s\n", add("5654654", "32132564154"));
//	return (0);
}
*/
