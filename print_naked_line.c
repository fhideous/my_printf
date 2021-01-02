#include "headers/ev_y_need_printf.h"
#include "stdio.h"

void print_oper (s_operation oper)
{
	printf("\n\n==================\n");
	printf("a.count: \t\t%d\n",oper.accuracy.count);
	printf("a.is_ar: \t\t%d\n",oper.accuracy.is_argument);
	printf("a.is_ze: \t\t%d\n",oper.accuracy.is_zero);
	printf("wi.count: \t\t%d\n",oper.width.count);
	printf("wi.is_ar: \t\t%d\n",oper.width.is_argument);
	printf("flag.i_lat: \t%d\n",oper.flag.is_lattice);
	printf("flag.i_sp: \t\t%d\n",oper.flag.is_space);
	printf("flag.i_pl: \t\t%d\n",oper.flag.is_plus);
	printf("flag.i_mi: \t\t%d\n",oper.flag.is_minus);
	printf("flag.i_zer: \t%d\n",oper.flag.is_zero);
	printf("==================\n\n");
}

int print_backslash(char** str)
{
	if (*(*str) == '\\')
		write(1, &"\\", 1);
	if (**str == '"')
		write(1, &"\"", 1);
//	if (**str != '\\' || **str != '"' || **str != '%')
	if (*(*str + 1) == '%')
		write(1, &"%", 1);
	(*str)++;
	return (1);
}

int print_percent (char** str)
{
	if (*(*str + 1) == '%')
	{
		(*str)++;
		(*str)++;
		write(1, &"%", 1);
		return (1);
	}
	return (0);
}

int print_n_spaces (int n)
{
	int i;

	i = n;
	while (i--)
		write (1, &" ", 1);
	return (n);
}

int print_line(char** str)
{
	int i;

	i = 0;
	while(**str != '\0')
	{
		if (**str == '\\')
			i += print_backslash(&*str);
		if (**str == '%')
		{
			if (print_percent(&*str))
			{
				i++;
				continue;
			}
			else
				return (i);
		}
		if (!(write(1, *str, 1)))
			return (-1);
		i++;
		(*str)++;
	}
	return (i);
}