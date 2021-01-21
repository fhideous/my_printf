/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing_int_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhideous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:34:22 by fhideous          #+#    #+#             */
/*   Updated: 2021/01/21 15:34:25 by fhideous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ev_y_need_printf.h"

int		join_and_return(char *add, char **str)
{
	char *tmp;

	if (!(tmp = ft_strjoin(add, *str)))
	{
		free(*str);
		return (-1);
	}
	free(*str);
	*str = tmp;
	return (0);
}

int		add_minus_to_naked_numb(char **str, int n_len, s_operation oper)
{
	char *tmp;

	if (**str != '0' && !space_count(*str))
	{
		if (!(tmp = ft_strjoin("-", *str)))
			return (-1);
		free(*str);
		*str = tmp;
	}
	else
	{
		*str = ft_memmove(*str + 1, *str, n_len);
		if (**str != '0' || oper.accuracy.count)
			(*str) = *str - 1;
		**str = '-';
	}
	return (0);
}

int		add_minus(char **str, int arg, s_operation oper)
{
	int i;
	int n_len;
	int check_malloc;

	n_len = (int)ft_strlen(*str) - space_count(*str);
	check_malloc = 0;
	if (((oper.flag.is_zero) && oper.width.count <= n_dig(arg)) ||
		(oper.accuracy.count >= (int)ft_strlen(*str)) ||
		(!oper.accuracy.count && oper.accuracy.is_zero && !oper.width.count))
		check_malloc = join_and_return("-", str);
	else if (!ft_isdigit(**str))
	{
		i = 0;
		while (*(*str + i) == ' ')
			i++;
		i = --i > 0 ? i : 0;
		*(*str + i) = '-';
	}
	else if (ft_isdigit(**str))
		check_malloc = add_minus_to_naked_numb(str, n_len, oper);
	if (check_malloc == -1)
		return (-1);
	return (1);
}

int		int_zero_processing(char **str, s_operation oper)
{
	char	*new_str;
	int		i;

	i = 0;
	if (oper.width.count == 0)
		return (0);
	else
	{
		if (!(new_str = line_from_same_asymb(' ', oper.width.count)))
			return (-1);
		*str = new_str;
	}
	if (!*str)
		return (-1);
	i += print_line(str);
	return (i);
}

int		int_arg(long int arg, s_operation oper)
{
	char	*str;
	int		i;

	i = 0;
	if (oper.accuracy.count || oper.accuracy.is_zero)
		oper.flag.is_zero = 0;
	if (!(str = ft_litoa(arg > 0 ? arg : -arg)))
		return (-1);
	if (*str == '0' && oper.accuracy.is_zero)
	{
		i = int_zero_processing(&str, oper);
		return (i);
	}
	if (oper.accuracy.count > 0)
		i += accuracy_check(&str, oper);
	if (oper.width.count > (int)ft_strlen(str))
		i += width_check(&str, oper);
	if (arg < 0)
		if (add_minus(&str, -1 * arg, oper) == -1)
			return (-1);
	i += print_line(&str);
	return (i);
}
