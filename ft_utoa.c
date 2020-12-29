#include "../git/headers/libft.h"
#include <stdlib.h>

static int		ft_len_n(unsigned int n)
{
	if (n / 10 != 0)
		return (1 + ft_len_n(n / 10));
	return (1);
}

static int		ft_power_ten(unsigned int n)
{
	if (n > 1)
		return (10 * ft_power_ten(n - 1));
	return (1);
}

static char	*crt_str(unsigned int n, int len)
{
	char	*str;
	int		i;

	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	i = 0;
	while (len)
	{
		str[i] = n / ft_power_ten(len) + 48;
		n %= ft_power_ten(len);
		len--;
		i++;
	}
	return (str);
}

char	*ft_utoa(unsigned int n)
{
	int				len;

	len = 0;
	len += ft_len_n(n);
	return (crt_str(n, len));
}
