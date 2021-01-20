#include "../headers/ev_y_need_printf.h"

long int			n_dig(long int a)
{
	if (a / 10 != 0)
		return (1 + n_dig(a / 10));
	return (1);
}

unsigned long int	un_dig(unsigned long int a)
{
	if (a / 10 != 0)
		return (1 + un_dig(a / 10));
	return (1);
}

int					ft_is_spec(char ch)
{
	if (ch == 'd' || ch == 'i'
		|| ch == 's' || ch == 'c'
		|| ch == 'u' || ch == 'p'
		|| ch == 'x' || ch == 'X')
		return (1);
	return (0);
}

int					space_count(char *str)
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

int					write_str(char *str)
{
	int i;

	i = 0;
	while (*(str + i))
	{
		if (write(1, str + i, 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int					write_n_symb(int chr, int n)
{
	int i;

	i = n;
	while (n-- > 0)
		if (write(1, &chr, 1) == -1)
			return (-1);
	return (i);
}
