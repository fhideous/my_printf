#include "headers/ev_y_need_printf.h"

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
	if (*(++*str) == '-')
	{
		oper->flag.is_minus = 1;
		check_flag(&*str, *&oper);
	}
	if (**str == '+')
	{
		oper->flag.is_plus = 1;
		check_flag(&*str, *&oper);
	}
	if (**str == '0' && oper->flag.is_zero == 0)
	{
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
void check_width(char** str, s_operation *oper)
{
	if (ft_isdigit (**str))
		oper->width.count = ft_atoi(*str);
	if (**str == '*')
		oper->width.is_argument = 1;
	if (oper->width.count == 0)
		*str += (oper->width.is_argument);
	else
		*str += (n_dig(oper->width.count) + oper->width.is_argument);
}
// за точкой должно быть целое число, если указана только(.), то точность ==

// если указана точность, 0 не учитывается
void check_accuracy(char** str, s_operation *oper)
{
	*(*str)++;
	if (ft_isdigit (**str))
		oper->accuracy.count = ft_atoi(*str);
	else if (**str == '*')
		oper->accuracy.is_argument = 1;
	else
		oper->accuracy.is_zero = 1;
	*str += (n_dig(oper->accuracy.count) + oper->accuracy.is_argument);
}
// если спецификатор отличен от тех, что чуществует - ub
// если аргументов недостаточно - ub
void check_oper(char** str, s_operation *oper)
{
	unsigned int i;
	i = 0;
	check_flag(&*str, *&oper);
	check_width(&*str, *&oper);
	if (**str == '.')
		check_accuracy(&*str, *&oper);
}