#include "headers/ev_y_need_printf.h"

int n_dig(int a)
{
	if(a/10 != 0)
		return (1 + n_dig(a/10));
	return (1);
}

int write_str(char *str)
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

int write_n_symb(int chr, int n)
{
	int i;

	i = n;
	while (n-- > 0)
		if (write(1, &chr, 1) == - 1)
			return (-1);
	return (i);
}