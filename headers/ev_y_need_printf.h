/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ev_y_need_printf.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhideous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 19:43:25 by fhideous          #+#    #+#             */
/*   Updated: 2021/01/22 19:43:28 by fhideous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_GIT2_0_EV_Y_NEED_PRINTF_H
# define FT_PRINTF_GIT2_0_EV_Y_NEED_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

typedef	struct			s_operation
{
	struct {
		unsigned char	is_minus;
		unsigned char	is_plus;
		unsigned char	is_zero;
		unsigned char	is_space;
		unsigned char	is_lattice;
	}					flag;
	struct {
		unsigned char	is_argument;
		int				count;
	}					width;
	struct {
		unsigned char	is_argument;
		int				count;
		unsigned char	is_zero;
	}					accuracy;
}						t_operation;

long int				n_dig(long int a);
unsigned long int		un_dig(unsigned long int a);

void					print_n_char(int ch, int n);

int						print_backslash(char **str);
int						print_percent (char **str);
int						print_line(char **str);
void					ft_free(char **str);

void					struct_set (t_operation *oper);
void					find_flag(char **str, t_operation *oper);
int						find_width(char **str, t_operation *oper);
int						width_check_uint(char **str, t_operation oper);
int						find_accuracy(char **str, t_operation *oper);
void					find_oper(char **str, t_operation *oper);

int						ft_is_spec(char ch);
char					*line_from_same_asymb(int symb, int len);

int						check_star(const char *str, va_list *ap,
									t_operation *op);
int						space_count(char *str);

void					dec_hex(char **str, unsigned int len,
								unsigned long int arg, int is_low);
void					str_reverse(char **str, int step);
int						hex_check_width(char **str, int step, t_operation oper);

int						int_arg(long int arg, t_operation oper);
int						str_arg(char *str, t_operation oper);
int						char_arg(int arg, t_operation oper);
int						unsigned_arg (unsigned int arg, t_operation oper);
int						ptr_arg (unsigned long int arg, t_operation oper);
int						hex_arg(unsigned int arg, t_operation oper, int is_low);
int						percant_arg(int arg, t_operation oper);

char					*flag_zero_str(char *str, int len);
int						width_check(char **str, t_operation oper);
int						accuracy_check(char **str, t_operation oper);
int						width_check_str(char **str, t_operation oper);

#endif
