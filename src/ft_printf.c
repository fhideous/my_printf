#include "../headers/ft_printf.h"

int specifier_processing(va_list *ap, char **str, s_operation oper, int *count)
{
	int n;

	n = -1;
	if (**str == '%')
		n = percant_arg('%', oper);
	if (**str == 'd' || **str == 'i')
		n = int_arg(va_arg(*ap, int), oper);
	if (**str == 's')
		n = str_arg(va_arg(*ap, char*), oper);
	if (**str == 'c')
		n = char_arg(va_arg(*ap, int), oper);
	if (**str == 'u')
		n = unsigned_arg(va_arg(*ap, unsigned int), oper);
	if (**str == 'p')
		n = ptr_arg((unsigned long int)va_arg(*ap, void *), oper);
	if (**str == 'x')
		n = hex_arg(va_arg(*ap,  unsigned int), oper, 1);
	if (**str == 'X')
		n = hex_arg(va_arg(*ap,  unsigned int ), oper, 0);
	if(n != -1)
		*count += n;
	else
		return (-1);
	(++*str);
	return (0);
}

int		check_star (const char * str,  va_list *ap, s_operation *op)
{
	int i;

	i = -1;
	while (*(str + ++i) != '*' && !ft_is_spec((str[i])));
	if (*(str + i) != '*')
		return (1);
	if (*(str + i + 1) == '.' ||
	(ft_isalpha(*(str + i + 1)) && *(str + i - 1) != '.'))
	{
		op->width.count = va_arg(*ap, int);
		if (op->width.count < 0)
		{
			op->width.count *= -1;
			op->flag.is_minus = 1;
		}
	}
	if (*(str + i - 1) != '.')
		while (*(str + ++i) != '*' && !ft_isalpha((str[i])));
	if (*(str + i) == '*' && *(str + i - 1) == '.')
	{
		op->accuracy.count = va_arg(*ap,int);
		if (op->accuracy.count == 0)
			op->accuracy.is_zero = 1;
		if (op->accuracy.count < 0)
			op->accuracy.count = 0;
	}
	return (0);
}

int		ft_printf(const char *src_str, ...)
{
	va_list ap;
	int count;
	char *str;
	s_operation operation;

	count = 0;
	str = (char *)src_str;
	va_start(ap, src_str);
	while (str && *str)
	{
		if (((count += print_line(&str)) == -1))
			return (-1);
		if (*str == '\0')
			return (count);
		if (*str == '%')
		{
			struct_set(&operation);
			check_star(str, &ap, &operation);
			check_oper(&str, &operation);
			if (specifier_processing(&ap, &str, operation, &count) == -1)
				return (-1);
		}
	}
	va_end(ap);
	return (count);
}