/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implement_operatios.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhideous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:33:53 by fhideous          #+#    #+#             */
/*   Updated: 2021/01/21 15:33:55 by fhideous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ev_y_need_printf.h"

char	*line_from_same_asymb(int symb, int len)
{
	int		i;
	char	*str;

	if (len < 0)
		return (NULL);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	while (++i < len)
		str[i] = (char)symb;
	str[i] = '\0';
	return (str);
}

int		width_accuracy_diff(char **str, s_operation oper, int str_len)
{
	char *same_symb_l;

	if (!(same_symb_l = line_from_same_asymb(' ', oper.width.count)))
		return (-1);
	if (oper.flag.is_minus)
		same_symb_l = ft_memmove(same_symb_l, *str, str_len);
	else
	{
		if (oper.flag.is_zero)
			ft_memset(same_symb_l, '0', oper.width.count);
		same_symb_l = ft_memmove(same_symb_l + oper.width.count -
				str_len, *str, str_len) - oper.width.count + str_len;
	}
	free(*str);
	*str = same_symb_l;
	return (0);
}

int		width_check(char **str, s_operation oper)
{
	int diff_w_a;
	int str_len;

	str_len = ft_strlen(*str);
	diff_w_a = oper.width.count - oper.accuracy.count;
	if (diff_w_a >= 0)
		if ((width_accuracy_diff(str, oper, str_len)) == -1)
			return (-1);
	return (0);
}

int		width_check_uint(char **str, s_operation oper)
{
	int diff_w_a;
	int str_len;

	str_len = ft_strlen(*str);
	diff_w_a = oper.width.count - oper.accuracy.count;
	if (**str == '0' && oper.accuracy.is_zero)
		oper.accuracy.is_zero = 2;
	if (diff_w_a >= 0)
		if ((width_accuracy_diff(str, oper, str_len)) == -1)
			return (-1);
	if (oper.accuracy.is_zero == 2)
		ft_memset(*str, ' ', ft_strlen(*str));
	return (0);
}

int		accuracy_check(char **str, s_operation oper)
{
	int		diff_w_str;
	char	*same_symb_l;
	int		str_len;

	str_len = ft_strlen(*str);
	diff_w_str = oper.accuracy.count - str_len;
	if (diff_w_str > 0)
	{
		if (!(same_symb_l = line_from_same_asymb('0', oper.accuracy.count)))
			return (-1);
		same_symb_l = ft_memmove(same_symb_l + diff_w_str,
							*str, oper.accuracy.count) - diff_w_str;
		free(*str);
		*str = same_symb_l;
		return (0);
	}
	return (0);
}
