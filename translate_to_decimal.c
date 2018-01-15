#include "bistromatic.h"

static char *get_chunk(char *charset, char *expression)
{
	int i;
	int j;

	i = 0;
	while (get_index(charset, expression[i]) < 0)
		i++;
	if (!expression[i])
		return ("");
	j = i;
	while (get_index(charset, expression[j]) > 0)
		j++;
	j--;
	return (substring(expression, i, j));
}

char *translate_to_decimal(char *charset, char *expression)
{
	char *chunk;
	char *charset_duplicate;
	char *expression_duplicate;
	
	charset_duplicate = ft_strdup(charset);
	expression_duplicate = ft_strdup(expression);
	chunk = get_chunk(charset, expression);
	while (ft_strlen(chunk) > 0)
	{
		printf("Chunk: %s\n", chunk);
		expression = replace(expression, chunk, get_decimal(charset, chunk), 0);
		chunk = get_chunk(charset, expression);
	}
	return (expression);
}
