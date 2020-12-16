#include "headers/ev_y_need_printf.h"

char	*line_from_same_asymb(int symb, int len)
{
	int i;
	char *str;

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

int		width_check(char** str, s_operation oper)
{
	int diff_w_a;
	char *same_symb_l;
	int str_len;

	str_len = ft_strlen(*str);
	diff_w_a = oper.width.count - oper.accuracy.count;
	if (diff_w_a >= str_len)
	{
		if (!(same_symb_l = line_from_same_asymb(' ', oper.width.count)))
			return (-1);
		if (oper.flag.is_minus)
			same_symb_l = ft_memmove(same_symb_l, *str, str_len);
		else
			same_symb_l = ft_memmove(same_symb_l + oper.width.count - str_len, *str,
									 str_len) - oper.width.count + str_len;
		free(*str);
		*str = same_symb_l;
	}
	return (ft_strlen(*str));
}

int		is_plus_check(char **str, s_operation oper)
{
	char *sign_str;

	if (oper.flag.is_plus)
	{
		if (!(sign_str = ft_strjoin("+", *str)))
			return (-1);
		free((*str));
		*str = sign_str;
		return (1);
	}
	return (0);
}

int		accuracy_check(char **str, s_operation oper)
{
	char *sign_str;
	int diff_w_str;
	char *same_symb_l;
	int str_len;

	str_len = ft_strlen(*str);
	diff_w_str = oper.accuracy.count - str_len;
	if (diff_w_str > 0)
	{
		if (!(same_symb_l = line_from_same_asymb('0', oper.accuracy.count)))
			return (-1);
		same_symb_l = ft_memmove(same_symb_l + diff_w_str, *str, oper
		.accuracy.count) - diff_w_str;
		free(*str);
		*str = same_symb_l;
		diff_w_str += str_len;
	}
	else
		diff_w_str = str_len;
	return (diff_w_str);
}
