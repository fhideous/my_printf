/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sstuff_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhideous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:34:08 by fhideous          #+#    #+#             */
/*   Updated: 2021/01/21 15:34:12 by fhideous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ev_y_need_printf.h"

static char	check_hex_low(int n)
{
	if (n >= 0 && n <= 9)
		return ((char)(n + 48));
	if (n == 10)
		return ('a');
	if (n == 11)
		return ('b');
	if (n == 12)
		return ('c');
	if (n == 13)
		return ('d');
	if (n == 14)
		return ('e');
	if (n == 15)
		return ('f');
	return (-1);
}

static char	check_hex_high(int n)
{
	if (n >= 0 && n <= 9)
		return ((char)(n + 48));
	if (n == 10)
		return ('A');
	if (n == 11)
		return ('B');
	if (n == 12)
		return ('C');
	if (n == 13)
		return ('D');
	if (n == 14)
		return ('E');
	if (n == 15)
		return ('F');
	return (-1);
}

void		dec_hex(char **str, unsigned int len,
					unsigned long int arg, int is_low)
{
	unsigned int	rem;

	while (arg || arg / 16)
	{
		rem = arg % 16;
		arg /= 16;
		if (is_low)
			(*(*str + --len)) = check_hex_low(rem);
		else
			(*(*str + --len)) = check_hex_high(rem);
	}
}

void		str_reverse(char **str, int step)
{
	int i;

	i = 0;
	while (*(*str + i) == ' ')
		i++;
	if (i)
	{
		ft_memmove(*str, *str + i, ft_strlen(*str) - i);
		i = step;
		while (*(*str + i))
			*(*str + i++) = ' ';
	}
}

int			hex_check_width(char **str, int step, t_operation oper)
{
	int		i;
	char	*tmp;

	if (oper.flag.is_zero && !oper.accuracy.count && !oper.accuracy.is_zero)
		i = 48;
	else
		i = 32;
	if (!(tmp = line_from_same_asymb(i, oper.width.count)))
		return (-1);
	ft_memmove(tmp + (oper.width.count - step), *str, step);
	free(*str);
	*str = tmp;
	return (0);
}
