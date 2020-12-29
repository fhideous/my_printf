#include "headers/ev_y_need_printf.h"


//#include "headers/libft.h"

int int_arg(int arg, s_operation oper)
{
	char *str;
	int i;
	char *tmp;

	i = 0;
	str = ft_itoa(arg > 0 ? arg : -arg);
	//if (oper.flag.is_plus)
//		i += plus_flag(arg);
	if (*str == '0' && oper.accuracy.is_zero)
		return (0);
	if (oper.accuracy.count > 0)
		i += accuracy_check(&str, oper);
	if (arg < 0)
	{
		if (!(tmp = ft_strjoin("-", str)))
			return (-1);
		free(str);
		str = tmp;
	}
	if (oper.width.count > ft_strlen(str))
		i += width_check(&str, oper);
	i += print_line(&str);
	//free (str);   ////// Need to clear this shit
	return (i);
}

int str_arg(char *arg, s_operation oper)
{
	int i;
	char* tmp;
	char * str = ft_strjoin(arg, "");
	i = 0;
	if (oper.accuracy.is_zero)
		return (0);
	if (oper.accuracy.count > 0)
		i += accuracy_check_str(&str, oper);

//	i += space_check(&str, oper, str);
	if (oper.width.count > ft_strlen(str))
		i += width_check_str(&str, oper);
	//if (oper.accuracy.count != 0 || str != 0)
//	i += print_line(&str);
	while (*(str + i))
	{
		if (write(1, str + i, 1) == -1)
			return (-1);
		i++;
	}
	free(str);
	return (i);
}

int char_arg(int arg, s_operation oper)
{
	int i;
	char* tmp;

	if (arg == (char)'\0')
		return (0);
	char * str = calloc (2, sizeof(char));
	str[0] = (char)arg;
	i = 0;
	if (oper.accuracy.count > 0)
		i += accuracy_check_str(&str, oper);

//	i += space_check(&str, oper, str);
	if (oper.width.count > ft_strlen(str))
		i += width_check_str(&str, oper);
	//if (oper.accuracy.count != 0 || str != 0)
//	i += print_line(&str);
	while (*(str + i))
	{
		if (write(1, str + i, 1) == -1)
			return (-1);
		i++;
	}
	free(str);
	return (i);
}

int		unsigned_arg (unsigned int arg, s_operation oper)
{
	char *str;
	int i;
	char *tmp;

	i = 0;
	str = ft_utoa(arg);
	//if (oper.flag.is_plus)
//		i += plus_flag(arg);
	if (*str == '0' && oper.accuracy.is_zero)
		return (0);
	if (oper.accuracy.count > 0)
		i += accuracy_check(&str, oper);
	if (oper.width.count > ft_strlen(str))
		i += width_check(&str, oper);
	i += print_line(&str);
	//free (str);   ////// Need to clear this shit
	return (i);

}