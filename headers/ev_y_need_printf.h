#ifndef FT_PRINTF_GIT2_0_EV_Y_NEED_PRINTF_H
#define FT_PRINTF_GIT2_0_EV_Y_NEED_PRINTF_H

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>


typedef struct t_operation
{
	struct {
		unsigned char	is_minus;
		unsigned char	is_plus;
		unsigned char	is_zero;
		unsigned char	is_space;
		unsigned char	is_lattice;
	}flag;
	struct {
		unsigned char	is_argument;
		unsigned int	count;
	}width;
	struct {
		unsigned char	is_argument;
		unsigned int	count;
		unsigned  char	is_zero;
	}accuracy;
}				s_operation;

unsigned int		n_dig(unsigned int a);
void set_minus(char **str);
//unsigned int dectox_int(int a, char *s);
int		write_str(char *str);
int		write_n_symb(int chr, int n);

void	print_oper (s_operation oper);
int		print_backslash(char** str);
int		print_percent (char** str);
int		print_n_spaces (int n);
int		print_line(char** str);

void	struct_set (s_operation *oper);
void	check_flag(char **str, s_operation *oper);
void	check_width(char** str, s_operation *oper);
int		width_check_uint(char **str, s_operation oper);
void	check_accuracy(char** str, s_operation *oper);
void	check_oper(char** str, s_operation *oper);

char	*line_from_same_asymb(int symb, int len);

int		int_arg(int arg, s_operation oper);
int		str_arg(char *str, s_operation oper);
int		char_arg(int arg, s_operation oper);
int		unsigned_arg (unsigned int arg, s_operation oper);
int		ptr_arg (unsigned long int arg, s_operation oper);
int		hex_arg(unsigned long int arg, s_operation oper, int is_low);

int		plus_flag(int integer);
char	*flag_zero_str(char *str, int len);
int		width_check(char** str, s_operation oper);
int		accuracy_check(char **str, s_operation oper);
int		width_check_str(char** str, s_operation oper);
int		accuracy_check_str(char **str, s_operation oper);
int		is_plus_check(char **str, s_operation oper);
int		space_check(char **str, s_operation oper, int integer);
#endif
