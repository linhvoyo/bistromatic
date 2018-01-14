#include "bistromatic.h"
#include <stdio.h>
#define BUFF_SIZE 2

int validate(char *exp,char *base, char *size);

int main(int argc, char **argv)
{
	if (argc)
		printf("Arbitrary argc usage\n");
	if (argv)
		printf("Arbitrary argv usage\n");
	printf("%d - %d = %s\n", 26, -19, subtract("26", "-19"));
	printf("%d - %d = %s\n", 26, 19, subtract("26", "19"));
	printf("%d - %d = %s\n", -26, -19, subtract("-26", "-19"));
	printf("%d - %d = %s\n", -26, 19, subtract("-26", "19"));
	printf("%d - %d = %s\n", -5, 10, subtract("-5", "10"));
	printf("%d - %d = %s\n", -5, -10, subtract("-5", "-10"));
	printf("%d - %d = %s\n", 5, 10, subtract("5", "10"));
	printf("%d - %d = %s\n", 5, -10, subtract("5", "-10"));

/*
	printf("%s \n", divide("-5", "-4"));
	printf("%s \n", divide("99", "33"));
	printf("%s \n", divide("99", "-33"));
	printf("%s \n", divide("-99", "33"));
	printf("%s \n", divide("-99", "-33"));
	printf("%s \n", divide("50", "-65406540"));
*/
//	printf("%s\n", evaluate_expr("398 + 505 / 505 + 8 * (5 + 10) % 10"));
//	printf("%s\n", evaluate_expr("398 + 505 / 505 + 8 * (5 + 10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000877777777777777777777777777)"));
	
//	ft_atoi_str("398 + 505 / 505 + 8");
//
	printf("*****************SUBTRACTION************\n");
 	printf("%d - %d = %s\n", 5, 10, subtract("5", "10"));
 	printf("%d - %d = %s\n", 10, 5, subtract("10", "5"));
 	printf("%d - %d = %s, result should be %s\n", 16, 16, subtract("16", "16"), "0");
 	printf("%d - %d = %s, result should be: %s\n", 644, -377, subtract("644", "-377"), "1021");
 	printf("%d - %d = %s, result should be: %s\n", 644, 1000090, subtract("644", "1000090"), "-999446");
 	printf("%d - %d = %s, result should be: %s\n", 1000090, 644, subtract("1000090", "644"), "999446");
	printf("%d - %d = %s\n", 200, 200, subtract("200", "200"));
	printf("%d - %d = %s\n", -200, -200, subtract("-200", "-200"));
	printf("%d - %d = %s\n", -250, -250, subtract("-250", "-250"));
 	printf("%s - %s = %s, result should be: %s\n", "3000546090", "3000546089", subtract("3000546090", "3000546089"), "1");
 	printf("%s - %s = %s, result should be: %s\n", "20001230090", "600450344", subtract("20001230090", "600450344"), "19400779746");
 	printf("%s - %s = %s, result should be: %s\n", "600450344", "20001230090", subtract("600450344", "20001230090"), "-19400779746");
	printf("%s - %s = %s\n", "956", "550", subtract("956", "550"));
	printf("%s - %s = %s\n", "-956", "550", subtract("-956", "550"));
 	printf("%s - %s = %s, result should be: %s\n", "-65406540", "0", subtract("-65406540", "0"), "-65406540");


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
	printf("%s / %s = %s, result should be: %s\n", "50", "-65406540", divide("50", "-65406540"), "0");
	printf("%s / %s = %s, result should be: %s\n", "99999", "33", divide("99999", "33"), "3030"); 
	printf("%s / %s = %s, result should be: %s\n", "999999", "33", divide("999999", "33"), "30303"); 
	printf("%s / %s = %s, result should be: %s\n", "640549870897542310246578954612", "984651246541324", divide("640549870897542310246578954612", "984651246541324"), "650534768678282");
	printf("%s / %s = %s, result should be: %s\n", "98420000000000000000", "-77", divide("98420000000000000000", "-77"), "-1278181818181818181");


	printf("*****************MODULUS************\n");
	printf("%s %% %s = %s, result should be: %s\n", "7", "-3", modulo("7", "-3"), "1");
	printf("%s %% %s = %s, result should be: %s\n", "-20", "-6", modulo("-20", "-6"), "-2");
	printf("%s %% %s = %s, result should be: %s\n", "25", "5", modulo("25", "25"), "0");
	printf("%s %% %s = %s, result should be: %s\n", "25", "7", modulo("25", "7"), "4");
	printf("%s %% %s = %s, result should be: %s\n", "0", "25", modulo("0", "25"), "0");
	printf("%s %% %s = %s, result should be: %s\n", "0", "5", modulo("0", "5"), "0");
	printf("%s %% %s = %s, result should be: %s\n", "11", "7", modulo("11", "7"), "4");
	printf("%s %% %s = %s, result should be: %s\n", "16", "4", modulo("16", "4"), "0");
	printf("%s %% %s = %s, result should be: %s\n", "17", "4", modulo("17", "4"), "1");
	printf("%s %% %s = %s, result should be: %s\n", "250", "25", modulo("250", "25"), "0");
	printf("%s %% %s = %s, result should be: %s\n", "50", "-65406540", modulo("50", "-65406540"), "50");
	printf("%s %% %s = %s, result should be: %s\n", "-65406540", "50", modulo("-65406540", "50"), "-40");
	printf("%s %% %s = %s, result should be: %s\n", "9", "3", modulo("9", "3"), "0");
	printf("%s %% %s = %s, result should be: %s\n", "987", "4", modulo("987", "4"), "3");
	printf("%s %% %s = %s, result should be: %s\n", "987", "123", modulo("987", "123"), "3");
	printf("%s %% %s = %s, result should be: %s\n", "923498", "313", modulo("923498", "313"), "148");
	printf("%s %% %s = %s, result should be: %s\n", "984651", "-5647", modulo("984651", "-5647"), "2073");
	printf("%s %% %s = %s, result should be: %s\n", "-984651", "5647", modulo("-984651", "5647"), "-2073");
	printf("%s %% %s = %s, result should be: %s\n", "-984651", "-5647", modulo("-984651", "-5647"), "-2073");
	printf("%s %% %s = %s, result should be: %s\n", "98420000000000000000", "-77", modulo("98420000000000000000", "-77"), "63");
	printf("%s %% %s = %s, result should be: %s\n", "-65406540", "-999999999999", modulo("-65406540", "-999999999999"), "-65406540");
	printf("%s %% %s = %s, result should be: %s\n", "99999", "33", modulo("99999", "33"), "9");
	printf("%s %% %s = %s, result should be: %s\n", "-7", "-4", modulo("-7", "-4"), "-3");
	printf("%s %% %s = %s, result should be: %s\n", "-7", "4", modulo("-7", "4"), "-3");
	printf("%s %% %s = %s, result should be: %s\n", "7", "4", modulo("7", "4"), "3");
	printf("%s %% %s = %s, result should be: %s\n", "7", "-4", modulo("7", "-4"), "3");


	printf("*****************BASE CONVERSION************\n");
	char *charset;
	char *decimal;
	char *correct_result;
	charset = "01";
	decimal = "1";
	correct_result = "1";
	printf("%s to base %lu (%s) = %s, result should be: %s\n", decimal, ft_strlen(charset), charset, base(charset, decimal), correct_result);
	printf("%s to base %lu (%s) = %s, result should be: %s\n", decimal, ft_strlen(charset), charset, base(charset, decimal), correct_result);
	charset = "0123456789ABCDEF";
	decimal = "16";
	correct_result = "10";
	printf("%s to base %lu (%s) = %s, result should be: %s\n", decimal, ft_strlen(charset), charset, base(charset, decimal), correct_result);
	charset = "0123456789ABCDEF";
	decimal = "1000";
	correct_result = "3E8";
	printf("%s to base %lu (%s) = %s, result should be: %s\n", decimal, ft_strlen(charset), charset, base(charset, decimal), correct_result);
	charset = "0123456789ABCDEF";
	decimal = "255";
	correct_result = "FF";
	printf("%s to base %lu (%s) = %s, result should be: %s\n", decimal, ft_strlen(charset), charset, base(charset, decimal), correct_result);
	charset = "0123456789ABCDEF";
	decimal = "256";
	correct_result = "100";
	printf("%s to base %lu (%s) = %s, result should be: %s\n", decimal, ft_strlen(charset), charset, base(charset, decimal), correct_result);
	charset = "0123456789ABCDEF";
	decimal = "1065400";
	correct_result = "1041B8";
	printf("%s to base %lu (%s) = %s, result should be: %s\n", decimal, ft_strlen(charset), charset, base(charset, decimal), correct_result);
	charset = "01";
	decimal = "1065400";
	correct_result = "100000100000110111000";
	printf("%s to base %lu (%s) = %s, result should be: %s\n", decimal, ft_strlen(charset), charset, base(charset, decimal), correct_result);
	charset = "01";
	decimal = "5";
	correct_result = "101";
	printf("%s to base %lu (%s) = %s, result should be: %s\n", decimal, ft_strlen(charset), charset, base(charset, decimal), correct_result);
	charset = "01";
	decimal = "15";
	correct_result = "1111";
	printf("%s to base %lu (%s) = %s, result should be: %s\n", decimal, ft_strlen(charset), charset, base(charset, decimal), correct_result);
	charset = "01";
	decimal = "16";
	correct_result = "10000";
	printf("%s to base %lu (%s) = %s, result should be: %s\n", decimal, ft_strlen(charset), charset, base(charset, decimal), correct_result);
	charset = "0123456789ABC";
	decimal = "50";
	correct_result = "3B";
	printf("%s to base %lu (%s) = %s, result should be: %s\n", decimal, ft_strlen(charset), charset, base(charset, decimal), correct_result);
	charset = "0123456789ABC";
	decimal = "11";
	correct_result = "B";
	printf("%s to base %lu (%s) = %s, result should be: %s\n", decimal, ft_strlen(charset), charset, base(charset, decimal), correct_result);
	charset = "0123456789A";
	decimal = "231";
	correct_result = "1A0";
	printf("%s to base %lu (%s) = %s, result should be: %s\n", decimal, ft_strlen(charset), charset, base(charset, decimal), correct_result);
	charset = "~^@\\!;i &[]";
	decimal = "231";
	correct_result = "^]~";
	printf("%s to base %lu (%s) = %s, result should be: %s\n", decimal, ft_strlen(charset), charset, base(charset, decimal), correct_result);
	charset = "0123456789ABCDEF";
	decimal = "98789748978999999999999999999999999966666666666666666699996545694597056";
	correct_result = "E5050C1073D089A752E28A6018859DC5068A9A7133421F3E40BDA887FC0";
	printf("%s to base %lu (%s) = %s, result should be: %s\n", decimal, ft_strlen(charset), charset, base(charset, decimal), correct_result);
	charset = "0123456789ABCDEF";
	decimal = "987897489789999999999999999999999999666666665456456456456465465465465405640564056465748978974089456213231056105610562302610564561056045615604564065746579865406666666666699996545694597056";
	correct_result = "3A1FB60E78A3B0DD3D845BD0AF5E0C95B7C39285C64084B4222924EBA836DB956ABB8FB372D091D24D03980F8A0703A1FCF32F0025210DFBE76EFDBBA8A99BD3285C4DDCD8239D8E159FA887FC0";
	printf("%s to base %lu (%s) = %s, result should be: %s\n", decimal, ft_strlen(charset), charset, base(charset, decimal), correct_result);

/*
	char buf[BUFF_SIZE + 1];
	int ret;
	char *exp;
	char *tmp;

	exp = ft_strnew(0);
	tmp = ft_strnew(0);
	if (argc != 3)

	char buf[BUFF_SIZE + 1];
	int ret;
	char *exp;
	char *tmp;

	exp = ft_strnew(0);
	tmp = ft_strnew(0);
	if (argc != 3)
	{
		ft_putstr("syntax error\n");
		return (-1);
	}
	while ((ret = read(0, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		tmp = exp;
		exp = ft_strjoin(tmp, buf);
		free(tmp);
	}
	exp[ft_strlen(exp) - 1] = '\0';
	if (!(validate(exp, argv[1], argv[2])))
	{
		ft_putstr("syntax error\n");
		return (-1);
	}
	else
	{
		puts(exp);
		ft_putstr(evaluate_expr(exp));
	}
	close(0);
	ft_putchar('\n');
*/
	return (0);
}
