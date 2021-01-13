#include "libft.h"

int				ft_atoi(const char *str)
{
	int			answ;
	int			i;
	signed char	neg;

	i = 0;
	neg = 1;
	answ = 0;
	while ((str[i] == ' ') || (str[i] == '\f') ||
			(str[i] == '\t') || (str[i] == '\v') ||
				(str[i] == '\n') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		answ = 10 * answ;
		answ = answ + (unsigned int)str[i] - '0';
		i++;
	}
	return (neg * answ);
}
