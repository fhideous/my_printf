/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing_hex_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhideous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:34:18 by fhideous          #+#    #+#             */
/*   Updated: 2021/01/21 15:34:21 by fhideous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ev_y_need_printf.h"

int			ptr_arg(unsigned long int arg, t_operation oper)
{
	char			*str;
	unsigned int	i;
	unsigned int	len;
	char			*tmp;

	len = un_dig(arg) + 1;
	i = len;
	str = ft_calloc((len), sizeof(char));
	if (!arg)
		str[0] = '0';
	dec_hex(&str, len, arg, 1);
	i = 0;
	while (!ft_isalnum(str[i]) && i < len)
		str[i++] = '*';
	if (oper.accuracy.is_zero && len == 2)
		i = len;
	if (!(tmp = ft_substr(str, i, len - i)))
		return (-1);
	free(str);
	str = ft_strjoin("0x", tmp);
	free(tmp);
	width_check_str(&str, oper);
	i = print_line(&str);
	free(str - i);
	return (i);
}

int			accuracy_hex_check(char **str, t_operation oper)
{
	char	*same_symb_l;
	int		str_len;
	int		step;

	str_len = ft_strlen(*str);
	step = oper.accuracy.count;
	if (str_len < oper.accuracy.count)
	{
		if (!(same_symb_l = line_from_same_asymb('0', oper.accuracy.count)))
			return (-1);
		ft_memmove(same_symb_l +
				(oper.accuracy.count - str_len), *str, str_len);
		free(*str);
		*str = same_symb_l;
	}
	else
		step = str_len;
	if (oper.width.count > oper.accuracy.count && oper.width.count > str_len)
		if (hex_check_width(str, step, oper) == -1)
			return (-1);
	if (oper.flag.is_minus)
		str_reverse(str, step);
	return (0);
}

int			hex_arg(unsigned int arg, t_operation oper, int is_low)
{
	char			*str;
	int				i;
	int				len;
	char			*tmp;

	if (oper.accuracy.count || oper.accuracy.is_zero)
		oper.flag.is_zero = 0;
	len = n_dig(arg) + 1;
	str = ft_calloc((len), sizeof(char));
	if (oper.flag.is_minus)
		oper.flag.is_zero = 0;
	if (arg == 0 && !oper.accuracy.is_zero)
		str[0] = 48;
	dec_hex(&str, len, arg, is_low);
	i = 0;
	while (!ft_isalnum(str[i]) && i < len)
		str[i++] = '*';
	if (!(tmp = ft_substr(str, i, len - i)))
		return (-1);
	free(str);
	str = tmp;
	accuracy_hex_check(&str, oper);
	i = print_line(&str);
	free(str - i);
	return (i);
}
