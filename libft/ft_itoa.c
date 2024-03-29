#include "libft.h"
#include <stdlib.h>

int		ft_len_n(int n)
{
	if (n / 10 != 0)
		return (1 + ft_len_n(n / 10));
	return (1);
}

int		ft_power_ten(int n)
{
	if (n > 1)
		return (10 * ft_power_ten(n - 1));
	return (1);
}

char	*crt_str(long n, int len, int is_neg)
{
	char	*str;
	int		i;

	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (is_neg)
		str[0] = '-';
	i = is_neg;
	while (len - is_neg)
	{
		str[i] = n / ft_power_ten(len - is_neg) + 48;
		n %= ft_power_ten(len - is_neg);
		len--;
		i++;
	}
	return (str);
}

char	*ft_itoa(size_t n)
{
	int				len;
	unsigned char	is_neg;
	long			new_n;
	char			*tmp;

	new_n = (long)n;
	len = 0;
	is_neg = 0;
	if (new_n < 0)
	{
		len = 1;
		is_neg = 1;
		new_n *= -1;
	}
	len += ft_len_n(n);
	tmp = crt_str(new_n, len, is_neg);
	return (tmp);
}

char	*ft_litoa(long int n)
{
	int				len;
	unsigned char	is_neg;
	char			*tmp;

	len = 0;
	is_neg = 0;
	if (n < 0)
	{
		len = 1;
		is_neg = 1;
		n *= -1;
	}
	len += ft_len_n(n);
	tmp = crt_str(n, len, is_neg);
	return (tmp);
}