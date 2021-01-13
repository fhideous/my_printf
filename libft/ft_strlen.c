#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t cnt;

	cnt = 0;
	while (*(s + cnt) != '\0')
		cnt++;
	return (cnt);
}
