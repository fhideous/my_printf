#include "libft.h"
#include "ft_printf.h"

typedef struct t_operation
{
	struct {
		unsigned char	is_minus;
		unsigned char	is_plus;
		unsigned char	is_zero;
		unsigned char	is_space;
		unsigned char	is_lattice;
	}flag;
	struct {
		unsigned char	is_argument;
		unsigned int	count;
	}width;
	struct {
		unsigned char	is_argument;
		unsigned int	count;
	}accuracy;
}				s_operation;

int print_line(char** str)
{
	int i;

	i = 0;
	while(**str != '%' || **str != '\0')
	{
		if (!(write(1, str, 1)))
			return (-1);
		i++;
		*str++;
	}
	return (i);
}

unsigned int check_flag(char **str, s_operation *oper)
{
	int i;

	i = -1;
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
	return(i += 1);
}

unsigned int check_width(char** str, s_operation *oper)
{
	if (ft_isdigit (**str))
		oper->width.count = ft_atoi(*str);
	else
		oper->width.count = 0;
	if (**str == '*')
		oper->width.is_argument = 1;
	*str += (1 + oper->width.count);
	return (oper->width.count);
}

unsigned int check_accuracy(char** str, s_operation *oper)
{
	if (ft_isdigit (**str))
		oper->accuracy.count = ft_atoi(*str);
	else
		oper->accuracy.count = 0;
	if (**str == '*')
		oper->accuracy.is_argument = 1;
	*str += (1 + oper->accuracy.count);
	return (oper->accuracy.count);
}

unsigned int check_oper(char** str, s_operation *oper)
{
	unsigned int i;
	i = 0;
	*str++;
	i += check_flag(&*str, *&oper);
	i += check_width(&*str, *&oper);
	if (**str == '/')
		i += check_accuracy(&*str, *&oper);
	return (i);
}

int ft_printf(const char *src_str, ...)
{
	va_list ap;
	int count;
	char *str;
	s_operation operation;

	str = (char *)src_str;
	va_start(ap, src_str);
	if ((count = print_line(&str) == -1))
		return (-1);
	if (*str == '\0')
		return (count);
	if (*str == '%')
		while (count += (int)(check_oper(&str, &operation)));
	return (count);
}