/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_common_fun.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhideous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:34:02 by fhideous          #+#    #+#             */
/*   Updated: 2021/01/21 15:34:07 by fhideous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ev_y_need_printf.h"

long int			n_dig(long int a)
{
	if (a / 10 != 0)
		return (1 + n_dig(a / 10));
	return (1);
}

unsigned long int	un_dig(unsigned long int a)
{
	if (a / 10 != 0)
		return (1 + un_dig(a / 10));
	return (1);
}

int					ft_is_spec(char ch)
{
	if (ch == 'd' || ch == 'i'
		|| ch == 's' || ch == 'c'
		|| ch == 'u' || ch == 'p'
		|| ch == 'x' || ch == 'X')
		return (1);
	return (0);
}

int					space_count(char *str)
{
	int i;
	int count;

	i = -1;
	count = 0;
	while (str[++i])
		if (str[i] == ' ')
			count++;
	return (count);
}
