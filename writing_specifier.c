#include "headers/ev_y_need_printf.h"


//#include "headers/libft.h"

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
//	if ((oper.flag.is_minus && oper.accuracy.count) && oper.width.count -
//	oper.accuracy.count)
//	{
////		i = 0;
////		while (!ft_isdigit(*(*str + i)))
////			i++;
//		if (!(tmp = ft_strjoin("-", *str)))
//			return (-1);
//		free(*str);
//		*str = tmp;
//	}else
	if ((oper.flag.is_zero) && oper.width.count <= n_dig(arg))
	{
//		i = 0;
//		while (!ft_isdigit(*(*str + i)))
//			i++;
		if (!(tmp = ft_strjoin("-", *str)))
			return (-1);

		free(*str);
		*str = tmp;
	} else
	if (oper.accuracy.count >= ft_strlen(*str)/* || (oper.accuracy.is_zero &&
	n_len == 1)*/)
	{
//		i = 0;
//		while (!ft_isdigit(*(*str + i)))
//			i++;
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

int int_arg(int arg, s_operation oper)
{
	char *str;
	int i;

	i = 0;
	if (oper.accuracy.count || oper.accuracy.is_zero)
		oper.flag.is_zero = 0;
	if (arg == -2147483648)
		str = ft_strjoin("", "-2147483648");
	else
		str = ft_itoa(arg > 0 ? arg : -arg);
//	if (oper.flag.is_minus)
//		oper.flag.is_zero = 0;
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
	if (oper.width.count > ft_strlen(str))
		i += width_check(&str, oper);
	if (arg < 0)
		add_minus(&str, arg, oper);
	i += print_line(&str);
	//free (str);   ////// Need to clear this shit
	return (i);
}

int str_arg(char *arg, s_operation oper)
{
	int i;
	char * str = ft_strjoin(arg, "");
	int arg_len;

	arg_len = ft_strlen(arg);
	i = 0;
	if (oper.accuracy.count > 0 || oper.accuracy.is_zero)
		i += accuracy_check_str(&str, oper);
	if (oper.width.count > ft_strlen(str))
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
	if (arg == (char)'\0')
		return (0);
	char * str = calloc (2, sizeof(char));
	str[0] = (char)arg;

	i = 0;
	if (oper.width.count > ft_strlen(str))
		i += width_check_str(&str, oper);
	if (oper.flag.is_zero)
			str = flag_zero_str(str, oper.width.count - 1);
	while (*(str + i))
	{
		if (write(1, str + i, 1) == -1)
			return (-1);
		i++;
	}
	free(str);
	return (i);
}

int		unsigned_arg (unsigned int arg, s_operation oper)
{
	char *str;
	int i;
//	char *tmp;

	i = 0;
	str = ft_utoa(arg);
	//if (oper.flag.is_plus)
//		i += plus_flag(arg);
	if (*str == '0' && oper.accuracy.is_zero)
		return (0);
	if (oper.accuracy.count > 0)
		i += accuracy_check(&str, oper);
	if (oper.width.count > ft_strlen(str))
		i += width_check(&str, oper);
	i += print_line(&str);
	//free (str);   ////// Need to clear this shit
	return (i);

}