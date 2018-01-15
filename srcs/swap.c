#include "bistromatic.h"

void swap(char **str1, char **str2)
{
	char *temp;

	temp = (*str1);
	(*str1) = (*str2);
	(*str2) = temp;
}
