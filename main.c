#include "bistromatic.h"

int main()
{
// 	printf("%s\n", subtract("5", "10"));
// 	printf("%s\n", subtract("10", "5"));
// 	printf("%s\n", subtract("644", "1000090"));
// 	printf("%s\n", subtract("1000090", "644"));
 	printf("%d + %d = %s\n", -99, 0, add("-99", "0"));
 	printf("%d + %d = %s\n", 0, -99, add("0", "-99"));
 	printf("%d + %d = %s\n", 0, 0, add("0", "0"));
 	printf("%d + %d = %s\n", 15, 80, add("15", "80"));
 	printf("%d + %d = %s\n", 100, 80, add("100", "80"));
 	printf("%d + %d = %s\n", 150, 900, add("150", "900"));
 	printf("%d + %d = %s\n", 200, -900, add("200", "-900"));
 	printf("%d + %d = %s\n", 200, -9999, add("200", "-9999"));
 	printf("%d + %d = %s\n", 2999, -9999, add("2999", "-9999"));
 	printf("%d + %d = %s\n", -200, 900, add("-200", "900"));
 	printf("%d + %d = %s\n", 200, -200, add("-200", "200"));
	printf("%d - %d = %s\n", 200, 200, subtract("200", "200"));
 	printf("%d + %d = %s\n", -200, -200, add("-200", "-200"));
	printf("%d + %d = %s\n", 999, 999, add("999", "999"));
	printf("%d + %d = %s\n", 999, 9999, add("999", "9999"));
	printf("%d + %d = %s\n", 9999, 999, add("9999", "999"));
	printf("%d + %d = %s\n", 99, 1, add("99", "1"));
// 	printf("%s\n", subtract("3000546090", "3000546089"));
// 	printf("%s\n", subtract("20001230090", "600450344"));
// 	printf("%s\n", subtract("600450344", "20001230090"));
//	printf("%s\n", multiplication("15", "80"));*/
//	printf("%s\n", subtract("956", "550"));
//	printf("%s\n", multiply("5000", "5000"));
//	printf("%s\n", multiply("10333147966386144929666651337523200000000", "10333147966386144929666651337523200000000"));
//	Answer: 106773946895230122545281450559425330223858126205527071528310538240000000000000000
//	printf("%s\n", multiply("999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999", "999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999"));
//	Answer: 999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999998999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001
//	printf("%d\n", number_cmp("570", "570"));
	printf("%d %% %d = %s\n", 923498, 313, modulo("923498", "313"));
	printf("%d %% %d = %s\n", 99999, 33, modulo("99999", "33")); // Breaking point for dumb modulo. Dumb modulo works until modulo("99999", "33").

//	Testing a lot of incremental additions.
//	int i = 0;
//	char *str1 = ft_strdup("0");
//	while (i < 1000000)
//	{
//		str1 = add(str1, "1");
//		printf("%s\n", str1);
//		i++;
//	}
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
//	printf("%s\n", divide("10", "3"));
//	printf("%s\n", divide("10", "2"));
	return (0);
}
