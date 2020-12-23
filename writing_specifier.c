#include "headers/ev_y_need_printf.h"

int int_arg(int arg, s_operation oper)
{
	char *str;
	int i;
	char *tmp;

	i = 0;
	str = ft_itoa(arg > 0 ? arg : -arg);
	//if (oper.flag.is_plus)
//		i += plus_flag(arg);

	if (oper.accuracy.count > 0)
		i += accuracy_check(&str, oper);
	if (arg < 0)
	{
		if (!(tmp = ft_strjoin("-", str)))
			return (-1);
		free(str);
		str = tmp;
	}
//	i += space_check(&str, oper, arg);
	if (oper.width.count > ft_strlen(str))
		i += width_check(&str, oper);
	//if (oper.accuracy.count != 0 || arg != 0)
	i += print_line(&str);
	//free (str);   ////// Need to clear this shit
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
