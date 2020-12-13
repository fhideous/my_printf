#include "headers/ev_y_need_printf.h"

int plus_flag(int integer)
{
	if (integer > 0)
		if (write (1, &"+", 1) == -1)
			return (-1);
	return (0);
}

int minus_flag(int ch, int accuracy)
{
	if (ch == 's' || ch == 'c')
	{

	}
	if (ch == 'd')
	{

	}
}

int width_check(int ch, s_operation oper, char *str)
{
	int len;
	int symb;

	if (oper.flag.is_zero)
		symb = '0';
	else
		symb = ' ';

	len = ft_strlen(str);
	if (ch == 'd')
	{
		if (!oper.flag.is_minus)
			write_str(str);
	}
	return (len);
}