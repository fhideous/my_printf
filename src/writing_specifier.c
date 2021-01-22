/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing_specifier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhideous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:34:32 by fhideous          #+#    #+#             */
/*   Updated: 2021/01/21 15:34:34 by fhideous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ev_y_need_printf.h"

int			unsigned_arg(unsigned int arg, t_operation oper)
{
	char	*str;
	int		i;

	i = 0;
	if (oper.accuracy.count || oper.accuracy.is_zero)
		oper.flag.is_zero = 0;
	str = ft_utoa(arg);
	if (*str == '0' && !oper.width.count && oper.accuracy.is_zero)
	{
		free(str);
		return (0);
	}
	if (oper.accuracy.count > 0)
		i += accuracy_check(&str, oper);
	if (oper.width.count >= (int)ft_strlen(str))
		i += width_check_uint(&str, oper);
	i += print_line(&str);
	free(str - i);
	str = NULL;
	return (i);
}

int			percant_arg(int arg, t_operation oper)
{
	int i;

	if (oper.width.count)
	{
		if (oper.flag.is_zero)
			i = 48;
		else
			i = 32;
		if (oper.flag.is_minus)
			write(1, &arg, 1);
		print_n_char(i, oper.width.count - 1);
		if (!oper.flag.is_minus)
			write(1, &arg, 1);
	}
	else if (oper.accuracy.is_zero)
	{
		write(1, "%", 1);
		return (1);
	}
	return (oper.width.count ? oper.width.count : 0);
}
