/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing_s_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhideous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:34:27 by fhideous          #+#    #+#             */
/*   Updated: 2021/01/21 15:34:31 by fhideous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ev_y_need_printf.h"

static void		choice_zero_str(char **str, s_operation oper, int arg_len)
{
	if (oper.width.count - oper.accuracy.count - arg_len > 0)
		*str = flag_zero_str(*str, oper.width.count - oper.accuracy.count -
				arg_len);
	if (oper.width.count > arg_len)
		*str = flag_zero_str(*str, oper.width.count - arg_len);
	if (oper.accuracy.count)
		*str = flag_zero_str(*str, oper.width.count - oper.accuracy.count);
}

char			*flag_zero_str(char *str, int len)
{
	if (len <= 0)
		return (str);
	while (len--)
		str[len] = '0';
	return (str);
}

int				width_check_str(char **str, s_operation oper)
{
	int		diff_w_a;
	char	*same_symb_l;
	int		str_len;

	str_len = ft_strlen(*str);
	diff_w_a = oper.width.count - ft_strlen(*str);
	if (diff_w_a >= 0)
	{
		if (!(same_symb_l = line_from_same_asymb(' ', oper.width.count)))
			return (-1);
		if (oper.flag.is_minus)
			same_symb_l = ft_memmove(same_symb_l, *str, str_len);
		else
			same_symb_l = ft_memmove(same_symb_l +
									oper.width.count - str_len,
							*str, str_len) - oper.width.count + str_len;
		ft_free(str);
		*str = same_symb_l;
	}
	return (0);
}

int				accuracy_check_str(char **str, s_operation oper)
{
	int		diff_w_str;

	diff_w_str = ft_strlen(*str) - oper.accuracy.count;
	if (diff_w_str > 0)
		*(*str + oper.accuracy.count) = '\0';
	return (0);
}

int				str_arg(char *arg, s_operation oper)
{
	int		i;
	char	*str;
	int		arg_len;

	if (!arg)
		str = ft_strjoin("(null)", "");
	else
		str = ft_strjoin(arg, "");
	arg_len = ft_strlen(str);
	i = 0;
	if (oper.accuracy.count > 0 || oper.accuracy.is_zero)
		i += accuracy_check_str(&str, oper);
	if (oper.width.count > (int)ft_strlen(str))
		i += width_check_str(&str, oper);
	if (oper.flag.is_zero)
		choice_zero_str(&str, oper, arg_len);
	while (*(str + i))
	{
		if (write(1, str + i, 1) == -1)
			return (-1);
		i++;
	}
	ft_free(&str);
	return (i);
}
