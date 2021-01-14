#include "../headers/ev_y_need_printf.h"

// 0 Работает только с d i o u x X a A e E f F g G
// если есть + , пробел игнорируется

void struct_set (s_operation *oper)
{
	oper->accuracy.count = 0;
	oper->accuracy.is_argument = 0;
	oper->accuracy.is_zero = 0;
	oper->width.count = 0;
	oper->width.is_argument = 0;
	oper->flag.is_lattice = 0;
	oper->flag.is_space = 0;
	oper->flag.is_minus = 0;
	oper->flag.is_plus = 0;
	oper->flag.is_zero = 0;
}

void check_flag(char **str, s_operation *oper)
{
	if (*(*str += 1) == '-')
	{
		oper->flag.is_minus = 1;
		oper->flag.is_zero = 0;
		check_flag(&*str, *&oper);
	}
	if (**str == '+')
	{
		oper->flag.is_plus = 1;
		check_flag(&*str, *&oper);
	}
	if (**str == '0' && oper->flag.is_zero == 0)
	{
		if(!oper->flag.is_minus)
			oper->flag.is_zero = 1;
		check_flag(&*str, *&oper);
	}
	if (**str == ' ')
	{
		oper->flag.is_space = 1;
		check_flag(&*str, *&oper);
	}
	if (**str == '#')
	{
		oper->flag.is_lattice = 1;
		check_flag(&*str, *&oper);
	}

}

// числа всегда положительные
int check_width(char** str, s_operation *oper)
{
	int width;

	if (ft_isdigit (**str))
	{
		width = ft_atoi(*str);
		oper->width.count = width;
		if (width == 0)
			*str += 1;
	}
		if (**str == '*')
		return (1);
	if (oper->width.count == 0)
		*str += (oper->width.is_argument);
	else
		*str += (n_dig(oper->width.count) + oper->width.is_argument);
	return (0);
}
// за точкой должно быть целое число, если указана только(.), то точность ==

int ft_is_spec(char ch)
{
	if (ch == 'd' || ch == 'i'
	|| ch == 's' || ch == 'c'
	|| ch == 'u' || ch == 'p'
	|| ch == 'x' || ch == 'X')
		return (1);
	return (0);
}
// если указана точность, 0 не учитывается
// при отриц точности - ничего
// при не сказанной точности - точность = 0
int check_accuracy(char** str, s_operation *oper)
{
	int skip;

	(*str)++;
	skip = 0;
	while (**str == '0')
		(*str)++;
	if (ft_isdigit (**str))
	{
		oper->accuracy.count = ft_atoi(*str);
//		oper->flag.is_zero = 0;
	}
	else if (**str == '*')
		return (1);
	else if (ft_is_spec(**str))
		oper->accuracy.is_zero = 1;
	while (!ft_isalpha(*(*str + skip)))
		skip++;
	*str += (oper->accuracy.is_argument + skip);
	return (0);
}
// если спецификатор отличен от тех, что чуществует - ub
// если аргументов недостаточно - ub
void check_oper(char** str, s_operation *oper)
{
//	unsigned int i;
//	i = 0;
	check_flag(&*str, *&oper);
	*str += check_width(&*str, *&oper);
	if (**str == '.')
		*str += check_accuracy(&*str, *&oper);
}