#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr_s;
	int		len;

	len = ft_strlen(s);
	ptr_s = (char*)s + len;
	while (len-- && *ptr_s != c)
	{
		ptr_s--;
	}
	if (*ptr_s == c)
		return (ptr_s);
	return (0);
}
