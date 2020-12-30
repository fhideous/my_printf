#include "headers/ft_printf.h"

int specifier_processing(va_list *ap, char **str, s_operation oper, int *count)
{
	int n;

	if (**str == '%')
		*(++*str);				//////Возможно так не стоит делать
	if (**str == 'd' || **str == 'i')
		n = int_arg(va_arg(*ap, int), oper);
	if (**str == 's')
		n = str_arg(va_arg(*ap, char*), oper);
	if (**str == 'c')
		n = char_arg(va_arg(*ap, int), oper);
	if (**str == 'u')
		n = unsigned_arg(va_arg(*ap, unsigned int), oper);
//	if (**str == 'x' || **str== 'X')
//		n = x_arg(va_arg(*ap, unsigned int));
	if(n != -1)
		*count += n;
	else
		return (-1);
	*(++*str);
	return (0);
}

void check_star (s_operation *oper, va_list *ap)
{
	if (oper->width.is_argument)
		oper->width.count = va_arg(*ap,unsigned int);
	if (oper->accuracy.is_argument)
		oper->accuracy.count = va_arg(*ap,unsigned int);
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
	while (str && *str)
	{
		if (((count += print_line(&str)) == -1))
			return (-1);
		if (*str == '\0')
			return (count);
		if (*str == '%')
		{
			struct_set(&operation);
			check_oper(&str, &operation);
			check_star(&operation, &ap);
			if (specifier_processing(&ap, &str, operation, &count) == -1)
				return (-1);
//			print_oper(operation);
		}
	}
	va_end(ap);
	return (count);
}