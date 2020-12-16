#include "headers/ev_y_need_printf.h"

int int_arg(int arg, s_operation oper)
{
	char *str;
	int i;
	int len;

	i = 0;
	str = ft_itoa(arg);
	//if (oper.flag.is_plus)
//		i += plus_flag(arg);

	len = ft_strlen(str);
	accuracy_check(&str, oper);
	 is_plus_check(&str, oper);
	i += width_check(&str, oper);
	print_line(&str);
	//free (str);
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
