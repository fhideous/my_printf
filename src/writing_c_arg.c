/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing_c_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhideous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:34:14 by fhideous          #+#    #+#             */
/*   Updated: 2021/01/21 15:34:16 by fhideous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ev_y_need_printf.h"

static int		char_null(int arg, char **str, s_operation op)
{
	int		i;

	i = op.width.count;
	if (op.flag.is_minus)
		write(1, &arg, 1);
	while (--i > 0)
		write(1, " ", 1);
	if (!op.flag.is_minus)
		write(1, &arg, 1);
	free(*str);
	return (op.width.count > 0 ? op.width.count : 1);
}

int				char_arg(int arg, s_operation oper)
{
	int		i;
	char	*str;

	str = ft_calloc(2, sizeof(char));
	str[0] = (char)arg;
	i = -1;
	if (arg == (char)'\0')
		return (char_null(arg, &str, oper));
	if (oper.width.count > (int)ft_strlen(str))
		i += width_check_str(&str, oper);
	if (oper.flag.is_zero)
		str = flag_zero_str(str, oper.width.count - 1);
	while (*(str + ++i))
		if (write(1, str + i, 1) == -1)
			return (-1);
	free(str);
	return (i);
}
