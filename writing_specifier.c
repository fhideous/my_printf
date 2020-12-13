#include "headers/ev_y_need_printf.h"

int int_arg(int arg, s_operation oper)
{
	char *str;
	int i;

	i = 0;
	str = ft_itoa(arg);
	if (oper.flag.is_plus)
		i = plus_flag(arg);
	if (oper.width.count )
	{

	}
	return (i);
}

int str_arg(char *arg, s_operation oper)
{
	int i;

	i = 0;
	while (*(arg + i))
	{
		if (write(1, arg + i, 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int char_arg(int arg, s_operation oper)
{
	if (write(1, &arg, 1) == -1)
		return (-1);

	return (1);
}
