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

int n_dig(int a);
int write_str(char *str);
int write_n_symb(int chr, int n);

void print_oper (s_operation oper);
int print_backslash(char** str);
int print_percent (char** str);
int print_line(char** str);

void struct_set (s_operation *oper);
void check_flag(char **str, s_operation *oper);
void check_width(char** str, s_operation *oper);
void check_accuracy(char** str, s_operation *oper);
void check_oper(char** str, s_operation *oper);

int int_arg(int arg, s_operation oper);
int str_arg(char *arg, s_operation oper);
int char_arg(int arg, s_operation oper);

int plus_flag(int integer);
int minus_flag(int ch, int accuracy);
int width_check(int ch, s_operation oper, char *str);

#endif
