#include "bistromatic.h"

int main()
{
	printf("*****************SUBTRACTION************\n");
 	printf("%d - %d = %s\n", 5, 10, subtract("5", "10"));
 	printf("%d - %d = %s\n", 10, 5, subtract("10", "5"));
 	printf("%d - %d = %s, result should be: %s\n", 644, 1000090, subtract("644", "1000090"), "-999446");
 	printf("%d - %d = %s, result should be: %s\n", 1000090, 644, subtract("1000090", "644"), "999446");
	printf("%d - %d = %s\n", 200, 200, subtract("200", "200"));
	printf("%d - %d = %s\n", -200, -200, subtract("-200", "-200"));
 	printf("%s - %s = %s, result should be: %s\n", "3000546090", "3000546089", subtract("3000546090", "3000546089"), "1");
 	printf("%s - %s = %s, result should be: %s\n", "20001230090", "600450344", subtract("20001230090", "600450344"), "19400779746");
 	printf("%s - %s = %s, result should be: %s\n", "600450344", "20001230090", subtract("600450344", "20001230090"), "-19400779746");
	printf("%s - %s = %s\n", "956", "550", subtract("956", "550"));

	printf("*****************ADDITION************\n");
 	printf("%d + %d = %s\n", -99, 0, add("-99", "0"));
 	printf("%d + %d = %s\n", 0, -99, add("0", "-99"));
 	printf("%d + %d = %s\n", 0, 0, add("0", "0"));
 	printf("%d + %d = %s\n", -15, -1, add("-15", "-1"));
 	printf("%d + %d = %s\n", -555, -1, add("-555", "-1"));
 	printf("%d + %d = %s\n", -1, -1, add("-1", "-1"));
 	printf("%d + %d = %s\n", 15, 80, add("15", "80"));
 	printf("%d + %d = %s\n", 100, 80, add("100", "80"));
 	printf("%d + %d = %s\n", 150, 900, add("150", "900"));
 	printf("%d + %d = %s\n", 200, -900, add("200", "-900"));
 	printf("%d + %d = %s\n", 200, -9999, add("200", "-9999"));
 	printf("%d + %d = %s\n", 2999, -9999, add("2999", "-9999"));
 	printf("%d + %d = %s\n", -200, 900, add("-200", "900"));
 	printf("%d + %d = %s\n", 200, -200, add("-200", "200"));
 	printf("%d + %d = %s\n", -200, -200, add("-200", "-200"));
	printf("%d + %d = %s\n", 999, 999, add("999", "999"));
	printf("%d + %d = %s\n", 999, 9999, add("999", "9999"));
	printf("%d + %d = %s\n", 9999, 999, add("9999", "999"));
	printf("%d + %d = %s\n", 99, 1, add("99", "1"));
	printf("%s + %s = %s, result should be: %s\n", "156705641798498747", "8927394867238468972364876234", "8927394867395174614163374981", add("156705641798498747", "8927394867238468972364876234"));

	printf("*****************MULTIPLICATION************\n");
	printf("%s * %s = %s, result should be: %s\n", "-10", "-10", multiply("-10", "-10"), "100");
	printf("%s * %s = %s, result should be: %s\n", "0", "80", multiply("", "80"), "0");
	printf("%s * %s = %s, result should be: %s\n", "80", "0", multiply("80", "0"), "0");
	printf("%s * %s = %s, result should be: %s\n", "15", "1", multiply("15", "1"), "15");
	printf("%s * %s = %s, result should be: %s\n", "1", "15", multiply("1", "15"), "15");
	printf("%s * %s = %s, result should be: %s\n", "5000", "5000", multiply("5000", "5000"), "25000000");
	printf("%s * %s = %s, result should be: %s\n", "10333147966386144929666651337523200000000", "10333147966386144929666651337523200000000", multiply("10333147966386144929666651337523200000000", "10333147966386144929666651337523200000000"), "106773946895230122545281450559425330223858126205527071528310538240000000000000000");


//	Testing a lot of incremental additions.
//	int i = 0;
//	char *str1 = ft_strdup("0");
//	while (i < 1000000)
//	{
//		str1 = add(str1, "1");
//		printf("%s\n", str1);
//		i++;
//	}
	printf("*****************DIVISION************\n");
	printf("%s / %s = %s\n", "10", "5", divide("10", "5"));
	printf("%s / %s = %s\n", "15", "5", divide("15", "5"));
	printf("%s / %s = %s\n", "20", "5", divide("20", "5"));
	printf("%s / %s = %s\n", "21", "5", divide("21", "5"));
	printf("%s / %s = %s\n", "22", "5", divide("22", "5"));
	printf("%s / %s = %s\n", "23", "5", divide("23", "5"));
	printf("%s / %s = %s\n", "24", "5", divide("24", "5"));
	printf("%s / %s = %s\n", "29", "5", divide("29", "5"));
	printf("%s / %s = %s\n", "30", "5", divide("30", "5"));
	printf("%s / %s = %s\n", "35", "5", divide("35", "5"));
	printf("%s / %s = %s\n", "100", "5", divide("100", "5"));
	printf("%s / %s = %s\n", "105", "5", divide("105", "5"));
	printf("%s / %s = %s\n", "106", "5", divide("106", "5"));
	printf("%s / %s = %s\n", "210", "5", divide("210", "5"));
	printf("%s / %s = %s\n", "200", "500", divide("200", "500"));
	printf("%s / %s = %s\n", "10", "3", divide("10", "3"));
	printf("%s / %s = %s\n", "10", "2", divide("10", "2"));
	printf("%s / %s = %s\n", "10", "0", divide("10", "0"));
	printf("%s / %s = %s, result should be: %s\n", "640549870897542310246578954612", "984651246541324", divide("640549870897542310246578954612", "984651246541324"), "650534768678282");

	printf("*****************MODULUS************\n");
	printf("%d %% %d = %s\n", 923498, 313, modulo("923498", "313"));
	printf("%d %% %d = %s\n", 99999, 33, modulo("99999", "33"));
	// Breaking point for dumb modulo. Dumb modulo works until modulo("99999", "33").
	return (0);
}
