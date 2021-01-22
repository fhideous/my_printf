/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhideous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:33:45 by fhideous          #+#    #+#             */
/*   Updated: 2021/01/21 15:33:51 by fhideous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				specifier_processing(va_list *ap, char **str,
										t_operation oper, int *count)
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
		n = hex_arg(va_arg(*ap, unsigned int), oper, 1);
	if (**str == 'X')
		n = hex_arg(va_arg(*ap, unsigned int), oper, 0);
	if (n != -1)
		*count += n;
	else
		return (-1);
	(++*str);
	return (0);
}

int				ft_printf(const char *src_str, ...)
{
	va_list		ap;
	int			count;
	char		*str;
	t_operation	operation;

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
			find_oper(&str, &operation);
			if (specifier_processing(&ap, &str, operation, &count) == -1)
				return (-1);
		}
	}
	va_end(ap);
	return (count);
}
