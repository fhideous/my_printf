#include "../headers/ev_y_need_printf.h"

void choice_zero_str(char **str, s_operation oper, int arg_len)
{
	if (oper.width.count - oper.accuracy.count - arg_len > 0)
		*str = flag_zero_str(*str, oper.width.count - oper.accuracy.count-
		arg_len);
	if (oper.width.count > arg_len)
		*str = flag_zero_str(*str, oper.width.count - arg_len);
	if (oper.accuracy.count)
		*str = flag_zero_str(*str, oper.width.count - oper.accuracy.count);
}

int str_arg(char *arg, s_operation oper)
{
	int i;
	char *str;
	int arg_len;

	if (!arg)
		str = ft_strjoin("(null)", "");
	else
		str = ft_strjoin(arg, "");
	arg_len = ft_strlen(str);
	i = 0;
	if (oper.accuracy.count > 0 || oper.accuracy.is_zero)
		i += accuracy_check_str(&str, oper);
	if (oper.width.count > (int)ft_strlen(str))
		i += width_check_str(&str, oper);
	if (oper.flag.is_zero)
		choice_zero_str(&str, oper, arg_len);
	while (*(str + i))
	{
		if (write(1, str + i, 1) == -1)
			return (-1);
		i++;
	}
	free(str);
	return (i);
}


int char_null (int arg, char **str, s_operation op)
{
	int i;
	i = op.width.count;
	if (op.flag.is_minus)
		write (1, &arg, 1);
	while (--i > 0)
		write(1, " ", 1);
	if (!op.flag.is_minus)
		write(1, &arg, 1);
	free(*str);
	return (op.width.count > 0 ? op.width.count : 1);
}

int char_arg(int arg, s_operation oper)
{
	int i;

	char * str;
	str = ft_calloc (2, sizeof(char));
	str[0] = (char)arg;

	i = -1;
	if (arg == (char) '\0')
		return(char_null(arg, &str, oper));
	if (oper.width.count > (int)ft_strlen(str))
		i += width_check_str(&str, oper);
	if (oper.flag.is_zero)
			str = flag_zero_str(str, oper.width.count - 1);
	while (*(str + ++i))
		if (write(1, str + i, 1) == -1)
			return (-1);
	free(str);
	return (i);
}

int		unsigned_arg (unsigned int arg, s_operation oper)
{
	char *str;
	int i;

	i = 0;
	if (oper.accuracy.count || oper.accuracy.is_zero)
		oper.flag.is_zero = 0;
	str = ft_utoa(arg);   // не подтягивается
	if (*str == '0' && !oper.width.count && oper.accuracy.is_zero)
	{
		free(str);
		return (0);
	}
	if (oper.accuracy.count > 0)
		i += accuracy_check(&str, oper);
	if (oper.width.count >= (int)ft_strlen(str))
		i += width_check_uint(&str, oper);
	i += print_line(&str);
		free (str - i);
	str = NULL;
	return (i);
}

static char	check_hex_low (int n)
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

static char	check_hex_high (int n)
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

void	dec_hex(char **str, unsigned int len,
			 unsigned long int arg)
{
	unsigned int	rem;

	while (arg || arg / 16)
	{
		rem = arg % 16;
		arg /= 16;
		(*(*str + --len)) = check_hex_low(rem);
	}
}

int		ptr_arg(unsigned long int arg, s_operation oper)
{
	char 			*str;
	unsigned int	i;
	unsigned int 	len;
	char			*tmp;

	len = un_dig(arg) + 1;
	i = len;
	str = ft_calloc ((len), sizeof(char));
	if (!arg)
		str[0] = '0';
	dec_hex(&str, len, arg);
	i = 0;
	while (!ft_isalnum(str[i]) && i < len)
		str[i++] = '*';
	if (oper.accuracy.is_zero && len == 2)
		i = len;
	if (!(tmp = ft_substr(str, i, len - i)))
		return (-1);
	free (str);
	str = ft_strjoin("0x", tmp);
	free(tmp);
	width_check_str(&str, oper);
	i = 0;
	i += print_line(&str);
	free(str - i);
	return (i);
}

int		accuracy_hex_check(char **str, s_operation oper)
{
	char *same_symb_l;
	int str_len;
	char *same_symb_l2;
	int i;
	int step;

	str_len = ft_strlen(*str);
	step = oper.accuracy.count;
	if (str_len < oper.accuracy.count)
	{
		if(!(same_symb_l = line_from_same_asymb('0', oper.accuracy.count)))
			return (-1);
		ft_memmove(same_symb_l + (oper.accuracy.count - str_len), *str, str_len);
		free(*str);
		*str = same_symb_l;
	}
	else
		step = str_len;
	if (oper.width.count > oper.accuracy.count && oper.width.count > str_len)
	{
		if (oper.flag.is_zero && !oper.accuracy.count && !oper.accuracy.is_zero)
			i = 48; //48
		else
			i = 32;
		if(!(same_symb_l2 = line_from_same_asymb(i, oper.width.count)))
			return (-1);
		ft_memmove(same_symb_l2 + (oper.width.count - step), *str, step);
		free(*str);
		*str = same_symb_l2;
	}
	if (oper.flag.is_minus)
	{
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
	return (0);
}

int		hex_arg (unsigned int arg, s_operation oper, int is_low)
{
	char			*str;
	int	i;
	int	len;
	unsigned int	rem;
	char			*tmp;

	if (oper.accuracy.count || oper.accuracy.is_zero)
		oper.flag.is_zero = 0;
	len = n_dig(arg) + 1;
	i = len;
	str = ft_calloc ((len), sizeof(char));
	if (oper.flag.is_minus)
		oper.flag.is_zero = 0;
	if (arg == 0 && !oper.accuracy.is_zero)
		str[0] = 48;
	while (arg || arg / 16  )
	{
		rem = arg % 16;
		arg /= 16;
		if (is_low)
			str[--i] = check_hex_low(rem);
		else
			str[--i] = check_hex_high(rem);
	}
	i = 0;
	while (!ft_isalnum(str[i]) && i < len)
		str[i++] = '*';
	if (!(tmp = ft_substr(str, i, len - i)))
		return (-1);
	free (str);
	str = tmp;
		accuracy_hex_check(&str, oper);
	i = 0;
	i += print_line(&str);
	free(str - i);
	return (i);
}

int		percant_arg(int arg, s_operation oper)
{
	int i;

	if (oper.width.count)
	{
		if (oper.flag.is_zero)
			i = 48; //48
		else
			i = 32;
		if (oper.flag.is_minus)
			write (1, &arg, 1);
		print_n_char(i, oper.width.count - 1);
		if (!oper.flag.is_minus)
			write (1, &arg, 1);
	}
	return (oper.width.count ? oper.width.count : 0);
}