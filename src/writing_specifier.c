#include "../headers/ev_y_need_printf.h"


//#include "headers/libft_a.h"

void			*f_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*ptr;
	const unsigned char	*src_ptr;

	if (dst == NULL && src == NULL)
		return (NULL);
	ptr = (unsigned char*)dst;
	src_ptr = (unsigned char*)src;
	if (src_ptr < ptr)
		while (len--)
			*(ptr + len) = *(src_ptr + len);
	else
		while (len--)
			*ptr++ = *src_ptr++;
	return (dst);
}

int space_count (char * str)
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

int add_minus (char** str, int arg, s_operation oper)
{
	char * tmp;
	int i;
	int n_len;

	n_len = (int)ft_strlen(*str) - space_count(*str);
	if ((oper.flag.is_zero) && oper.width.count <= n_dig(arg))
	{
		if (!(tmp = ft_strjoin("-", *str)))
			return (-1);
		free(*str);
		*str = tmp;
	} else
	if (oper.accuracy.count >= (int)ft_strlen(*str)/* || (oper.accuracy.is_zero &&
	n_len == 1)*/)
	{
		if (!(tmp = ft_strjoin("-", *str)))
			return (-1);
		free(*str);
		*str = tmp;
	}
	else if (!oper.accuracy.count &&oper.accuracy.is_zero && !oper.width.count)
	{
		if (!(tmp = ft_strjoin("-", *str)))
			return (-1);
		free(*str);
		*str = tmp;
	}
	else if (!ft_isdigit(**str))
	{
		i = 0;
		while (*(*str + i) == ' ')
			i++;
		i = --i > 0 ? i : 0;
		*(*str + i) = '-';
	}
	else if (ft_isdigit(**str))
	{
		if (**str != '0' && !space_count(*str))
		{
			if (!(tmp = ft_strjoin("-", *str)))
				return (-1);

			free(*str);
			*str = tmp;
		}else
		{
			*str = f_memmove(*str + 1, *str, n_len);
			if (**str != '0' || oper.accuracy.count)
				(*str) = *str - 1;
			**str = '-';
		}
	}
	return (1);
}

int int_arg(long int arg, s_operation oper)
{
	char *str;
	int i;

	i = 0;
	if (oper.accuracy.count || oper.accuracy.is_zero)
		oper.flag.is_zero = 0;
//	if (arg == -2147483648)
//		str = ft_strjoin("", "-2147483648");
//	else
		str = ft_itoa(arg > 0 ? arg : -arg);				////change to ltoa
	if (*str == '0' && oper.accuracy.is_zero)
	{
		if (oper.width.count == 0)
			return (0);
		else
			str = line_from_same_asymb(' ', oper.width.count);
		return(i+= print_line(&str));
	}
	if (oper.accuracy.count > 0)
		i += accuracy_check(&str, oper);
	if (oper.width.count > (int)ft_strlen(str))
		i += width_check(&str, oper);
	if (arg < 0 && arg != -2147483648)
		add_minus(&str, -1 * arg, oper);
	i += print_line(&str);
	//free (str);   ////// Need to clear this shit
	return (i);
}

char	*ft2_strjoin(char const *s1, char const *s2)
{
	char	*conc_str;
	size_t	s1_len;
	size_t	s2_len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	conc_str = (char *)malloc((s1_len + s2_len + 1) *sizeof(char));
	if (!conc_str)
		return (NULL);
	ft_memcpy(conc_str, s1, s1_len);
	ft_memcpy(conc_str + s1_len, s2, s2_len);
	*(conc_str + s1_len + s2_len) = '\0';
	return (conc_str);
}

int str_arg(char *arg, s_operation oper)
{
	int i;
	char * str;
	int arg_len;

	if (!arg)
		str = ft_strjoin("(null)", "");
	else
		str = ft2_strjoin(arg, "");
	arg_len = ft_strlen(str);
	i = 0;
	if (oper.accuracy.count > 0 || oper.accuracy.is_zero)
		i += accuracy_check_str(&str, oper);
	if (oper.width.count > (int)ft_strlen(str))
		i += width_check_str(&str, oper);
	if (oper.flag.is_zero)
	{
		if (oper.width.count - oper.accuracy.count - arg_len > 0)
			str = flag_zero_str(str, oper.width.count - oper.accuracy.count- arg_len);
		if (oper.width.count > arg_len)
			str = flag_zero_str(str, oper.width.count - arg_len);
		if (oper.accuracy.count)
			str = flag_zero_str(str, oper.width.count - oper.accuracy.count);
	}
	while (*(str + i))
	{
		if (write(1, str + i, 1) == -1)
			return (-1);
		i++;
	}
	free(str);
	return (i);
}

int char_arg(int arg, s_operation oper)
{
	int i;

	char * str;
	str = ft_calloc (2, sizeof(char));
	str[0] = (char)arg;

	i = -1;
	if (arg == (char) '\0')
	{
		i = oper.width.count;
		if (oper.flag.is_minus)
			write (1, &arg, 1);
		while (--i > 0)
			write(1, " ", 1);
		if (!oper.flag.is_minus)
			write(1, &arg, 1);
//		if (arg == (char) '\0' && !oper.width.count)
//			write(1, &arg, 1);
		free(str);
		return (oper.width.count > 0 ? oper.width.count : 1);
	}
	if (oper.width.count > (int)ft_strlen(str))
		i += width_check_str(&str, oper);
	if (oper.flag.is_zero)
			str = flag_zero_str(str, oper.width.count - 1);
	while (*(str + ++i))
		if (write(1, str + i, 1) == -1)
			return (-1);
	free(str);
//	if (arg == 0)
//		return (1);
	return (i);
}

int		unsigned_arg (unsigned int arg, s_operation oper)
{
	char *str;
	int i;

	i = 0;
//	str = ft_itoa(arg);
	if (oper.accuracy.count || oper.accuracy.is_zero)
		oper.flag.is_zero = 0;
	str = ft_utoa(arg);   // не подтягивается
	if (*str == '0' && !oper.width.count && oper.accuracy.is_zero)
		return (0);
	if (oper.accuracy.count > 0)
		i += accuracy_check(&str, oper);
	if (oper.width.count >= (int)ft_strlen(str))
		i += width_check_uint(&str, oper);
	i += print_line(&str);
	if (*str)			///// Wow, something interesting
		free (str);   ////// Need to clear this shit
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

int		ptr_arg (unsigned long int arg, s_operation oper)
{
	char	*str;
	unsigned int		i;
	unsigned int 	len;
	unsigned int	rem;
	char			*tmp;

	len = un_dig(arg) + 1;
	i = len;
	str = ft_calloc ((len), sizeof(char));
	if (!arg)
		str[0] = '0';
	while (arg || arg / 16  )
	{
		rem = arg % 16;
		arg /= 16;
		str[--i] = check_hex_low(rem);
	}
	i = 0;
	while (!ft_isalnum(str[i]) && i < len)
		str[i++] = '*';
	if (!(tmp = ft_substr(str, i, len - i)))
		return (-1);
	free (str);
	str = ft_strjoin("0x", tmp);

	width_check_str(&str, oper);
	i = 0;
	i += print_line(&str);
	free(tmp);
	//free(str);
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
//	if (oper.flag.is_zero)
//		oper.width.count++;
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
	if (oper.width.count > oper.accuracy.count && oper.width.count > str_len/*&& oper.accuracy.count != 0 && !oper.accuracy.is_zero*/)
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
	unsigned int	i;
	unsigned int	len;
	unsigned int	rem;
	char			*tmp;

//	if (arg == 0)
//		len = 1;
//	else
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
//	width_check_str(&str, oper);
//	if (oper.accuracy.count + oper.flag.is_zero < oper.width.count)
		accuracy_hex_check(&str, oper);
	i = 0;
	i += print_line(&str);

	return (i);
}