#include "headers/ft_printf.h"

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