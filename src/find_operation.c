#include "../headers/ev_y_need_printf.h"

void	struct_set(s_operation *oper)
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

void	find_flag(char **str, s_operation *oper)
{
	if (*(*str += 1) == '-')
	{
		oper->flag.is_minus = 1;
		oper->flag.is_zero = 0;
		find_flag(&*str, *&oper);
	}
	if (**str == '+')
	{
		oper->flag.is_plus = 1;
		find_flag(&*str, *&oper);
	}
	if (**str == '0')
	{
		if (!oper->flag.is_minus)
			oper->flag.is_zero = 1;
		find_flag(&*str, *&oper);
	}
	if (**str == ' ')
	{
		oper->flag.is_space = 1;
		find_flag(&*str, *&oper);
	}
}

int		find_width(char **str, s_operation *oper)
{
	int width;

	if (ft_isdigit(**str))
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

int		find_accuracy(char **str, s_operation *oper)
{
	int skip;

	(*str)++;
	skip = 0;
	while (**str == '0')
		(*str)++;
	if (ft_isdigit(**str))
	{
		oper->accuracy.count = ft_atoi(*str);
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

void	find_oper(char **str, s_operation *oper)
{
	find_flag(&*str, *&oper);
	*str += find_width(&*str, *&oper);
	if (**str == '.')
		*str += find_accuracy(&*str, *&oper);
}
