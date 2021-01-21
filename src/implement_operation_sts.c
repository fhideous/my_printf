#include "../headers/ev_y_need_printf.h"

char	*flag_zero_str(char *str, int len)
{
	if (len <= 0)
		return (str);
	while (len--)
		str[len] = '0';
	return (str);
}

int		width_check_str(char **str, s_operation oper)
{
	int		diff_w_a;
	char	*same_symb_l;
	int		str_len;

//	tmp = *str;
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
		free(*str);
		*str = same_symb_l;
	}
	return (0);
}

int		accuracy_check_str(char **str, s_operation oper)
{
	int		diff_w_str;

	diff_w_str = ft_strlen(*str) - oper.accuracy.count;
	if (diff_w_str > 0)
		*(*str + oper.accuracy.count) = '\0';
	return (0);
}
