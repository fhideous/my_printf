#include "../headers/ev_y_need_printf.h"

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
	if (diff_w_a >= 0)
	{
		if (!(same_symb_l = line_from_same_asymb(' ', oper.width.count)))
			return (-1);
		if (oper.flag.is_minus)
			same_symb_l = ft_memmove(same_symb_l, *str, str_len);
		else
		{
			if (oper.flag.is_zero)
				ft_memset(same_symb_l, '0', oper.width.count);
			same_symb_l = ft_memmove(same_symb_l + oper.width.count -
									 str_len, *str, str_len) -
						  oper.width.count + str_len;
		}
		free(*str);
		*str = same_symb_l;
	}
	return (0);
}

int		width_check_uint(char **str, s_operation oper)
{
	int diff_w_a;
	char *same_symb_l;
	int str_len;
	int diff_l_w;

	str_len = ft_strlen(*str);
	diff_l_w = 0;
	diff_w_a = oper.width.count - oper.accuracy.count;
	if (oper.accuracy.count )
		diff_l_w = oper.accuracy.count - str_len;
	else if (oper.width.count)
		diff_l_w = oper.width.count - str_len;
	if (**str == '0' && oper.accuracy.is_zero)
		oper.accuracy.is_zero = 2;
	diff_l_w = diff_l_w > 0 ? diff_l_w : 0;
	if (diff_w_a >= 0)
	{
		if (!(same_symb_l = line_from_same_asymb(' ', oper.width.count)))
			return (-1);
		if (oper.flag.is_minus)
			same_symb_l = ft_memmove(same_symb_l, *str, str_len);
		else
		{
			if (oper.flag.is_zero && diff_l_w)
				ft_memset(same_symb_l, '0', diff_l_w);
			same_symb_l = ft_memmove(same_symb_l + oper.width.count -
									 str_len, *str, str_len) -
						  oper.width.count + str_len;
		}
		free(*str);
		*str = same_symb_l;
	}
	if (oper.accuracy.is_zero == 2)
		ft_memset(*str, ' ', ft_strlen(*str));
	return (0);
}

char*	flag_zero_str (char *str, int len)
{
	if (len <= 0)
		return (str);
	while (len--)
	{
		str[len] = '0';
	}
	return (str);
}

int		width_check_str(char** str, s_operation oper)
{
	int diff_w_a;
	char *same_symb_l;
	int str_len;

	str_len = ft_strlen(*str);
	diff_w_a = oper.width.count - ft_strlen(*str);
	if (diff_w_a >= 0)
	{
		if (!(same_symb_l = line_from_same_asymb(' ', oper.width.count)))
			return (-1);
		if (oper.flag.is_minus )
			same_symb_l = ft_memmove(same_symb_l, *str, str_len);
		else
			same_symb_l = ft_memmove(same_symb_l + oper.width.count -
									 str_len, *str, str_len) -
						  oper.width.count + str_len;
//		free(*str);				//need to clear
		*str = same_symb_l;
	}
	return (0);
}

int		space_check(char **str, s_operation oper, int arg)
{
	char	*sign_str;

	if (!oper.flag.is_plus && !oper.flag.is_space)
		return (0);
	if (arg < 0)
	{
		if (!(sign_str = ft_strjoin("-", *str)))
			return (-1);
		return (0);
	}
	if (!(sign_str = ft_strjoin(" ", *str)))
		return (-1);
	if (oper.flag.is_plus)
		sign_str[0]= '+';
	free((*str));
	*str = sign_str;
	return (1);
}

int		accuracy_check(char **str, s_operation oper)
{
	int		diff_w_str;
	char	*same_symb_l;
	int		str_len;

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
		return (0);
	}
	return (0);
}

int		accuracy_check_str(char **str, s_operation oper)
{
	int		diff_w_str;
//	int		diff_a_w;

	diff_w_str = ft_strlen(*str) - oper.accuracy.count;
//	diff_a_w = oper.accuracy.count - oper.width.count;

	if (diff_w_str > 0)
		*(*str + oper.accuracy.count) = '\0';
	return (0);
}
