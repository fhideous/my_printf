#include <stdio.h>
#include "../lib/libft.h"
#include "headers/ft_printf.h"
//https://www.khronos.org/registry/OpenCL/sdk/1.2/docs/man/xhtml/printfFunction.html

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
		unsigned  char	is_zero;
	}accuracy;
}				s_operation;

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
		*(*str)++;
		*(*str)++;
		write(1, &"%", 1);
		return (1);
	}
	return (0);
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
// 0 Работает только с d i o u x X a A e E f F g G
// если есть + , пробел игнорируется

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

int n_dig(int a)
{
	if(a/10 != 0)
		return (1 + n_dig(a/10));
	return (1);
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

int plus_flag(int integer)
{
	if (integer > 0)
		if (write (1, &"+", 1) == -1)
			return (-1);
	return (0);
}

int write_str(char *str)
{
	int i;

	i = 0;
	while (*(str + i))
	{
		if (write(1, str + i, 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int write_n_symb(int chr, int n)
{
	int i;

	i = n;
	while (n-- > 0)
		if (write(1, &chr, 1) == - 1)
			return (-1);
	return (i);
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
			write_str()

	}
}

int int_arg(int arg, s_operation oper)
{
	char *str;
	int i;

	i = 0;
	str = ft_itoa(arg);
	if (oper.flag.is_plus)
		i = plus_flag(arg);
	if (oper.width.count )
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

int specifier_processing(va_list *ap, char **str, s_operation oper, int *count)
{
	int n;

	if (**str == '%')
		*(++*str);				//////Возможно так не стоит делать
	if (**str == 'd')
		n = int_arg(va_arg(*ap, int), oper);
	if (**str == 's')
		n = str_arg(va_arg(*ap, char*), oper);
	if (**str == 'c')
		n = char_arg(va_arg(*ap, int), oper);

	if(n != -1)
		*count += n;
	else
		return (-1);
	*(++*str);
	return (0);
}

int ft_printf(const char *src_str, ...)
{
	va_list ap;
	int count;
	char *str;
	s_operation operation;

	count = 0;
	str = (char *)src_str;
	va_start(ap, src_str);
	while (*str)
	{
		if (((count += print_line(&str)) == -1))
			return (-1);
		if (*str == '\0')
			return (count);
		if (*str == '%')
		{
			struct_set(&operation);
			check_oper(&str, &operation);
			if (specifier_processing(&ap, &str, operation, &count) == -1)
				return (-1);
//			print_oper(operation);
		}
	}
	va_end(ap);
	return (count);
}