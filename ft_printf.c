#include "headers/ft_printf.h"

int specifier_processing(va_list *ap, char **str, s_operation oper, int *count)
{
	int n;

	if (**str == '%')
		(++*str);
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
		n = hex_arg(va_arg(*ap, unsigned long int),oper, 1);
	if (**str == 'X')
		n = hex_arg(va_arg(*ap, unsigned long int ),oper, 0);
	if(n != -1)
		*count += n;
	else
		return (-1);
	(++*str);
	return (0);
}

//void	check_star (s_operation *oper, va_list *ap)
//{
//	if (oper->width.is_argument)
//		oper->width.count = va_arg(*ap,unsigned int);
//	if (oper->accuracy.is_argument)
//		oper->accuracy.count = va_arg(*ap,unsigned int);
//}

char*	check_star (const char * str, va_list *ap)
{
	int i;
	char *res;
	char *tmp;
	char *tmp2;

	i = 0;
	while (*(str + i) != '*' && !ft_is_spec((str[i])))
		i++;
	res = ft_strjoin("", str);
	if (*(str + i) != '*')
		return (res);
	res += i + 1;
	i = va_arg(*ap, int);
	tmp = ft_itoa(i);
	if (!(tmp2 = ft_strjoin(tmp, res)))
		return (NULL);
	free(res -= 2);
	free(tmp);
	if (!(res = ft_strjoin("%",tmp2)))
		return (NULL);
	free(tmp2);
	return (res);
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
			str = check_star(str, &ap);
			struct_set(&operation);
			check_oper(&str, &operation);
		//	ptr_arg(398313224, operation);
			if (specifier_processing(&ap, &str, operation, &count) == -1)
				return (-1);
//			print_oper(operation);
		}
	}
	free((void *)src_str);
	va_end(ap);
	return (count);
}