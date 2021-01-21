/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_naked_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhideous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:33:57 by fhideous          #+#    #+#             */
/*   Updated: 2021/01/21 15:34:01 by fhideous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ev_y_need_printf.h"
#include "stdio.h"

int		print_backslash(char **str)
{
	if (*(*str) == '\\')
		write(1, &"\\", 1);
	if (**str == '"')
		write(1, &"\"", 1);
	if (*(*str + 1) == '%')
		write(1, &"%", 1);
	(*str)++;
	return (1);
}

int		print_percent(char **str)
{
	if (*(*str + 1) == '%')
	{
		(*str)++;
		(*str)++;
		write(1, &"%", 1);
		return (1);
	}
	return (0);
}

void	print_n_char(int ch, int n)
{
	while (n--)
		write(1, &ch, 1);
}

int		print_line(char **str)
{
	int i;

	i = 0;
	while (**str != '\0')
	{
		if (**str == '\\')
			i += print_backslash(&*str);
		if (**str == '%')
		{
			if (print_percent(&*str))
			{
				i++;
				continue;
			}
			else
				return (i);
		}
		if (!(write(1, *str, 1)))
			return (-1);
		i++;
		(*str)++;
	}
	return (i);
}
