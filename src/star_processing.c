/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   star_processing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhideous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:43:38 by fhideous          #+#    #+#             */
/*   Updated: 2021/01/21 16:43:42 by fhideous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ev_y_need_printf.h"

static void		star_width(va_list *ap, s_operation *op)
{
	op->width.count = va_arg(*ap, int);
	if (op->width.count < 0)
	{
		op->width.count *= -1;
		op->flag.is_minus = 1;
	}
}

static void		star_accuracy(va_list *ap, s_operation *op)
{
	op->accuracy.count = va_arg(*ap, int);
	if (op->accuracy.count == 0)
		op->accuracy.is_zero = 1;
	if (op->accuracy.count < 0)
		op->accuracy.count = 0;
}

int				check_star(const char *str, va_list *ap, s_operation *op)
{
	int i;

	i = -1;
	while (*(str + ++i) != '*')
		if (ft_isalpha(str[i]))
			break ;
	if (*(str + i) != '*')
		return (1);
	if (*(str + i + 1) == '.' ||
		(ft_isalpha(*(str + i + 1)) && *(str + i - 1) != '.'))
		star_width(ap, op);
	if (*(str + i - 1) != '.')
		while (*(str + ++i) != '*')
			if (ft_isalpha(str[i]))
				break ;
	if (*(str + i) == '*' && *(str + i - 1) == '.')
		star_accuracy(ap, op);
	return (0);
}
