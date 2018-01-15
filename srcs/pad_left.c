#include "../includes/bistromatic.h"

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
