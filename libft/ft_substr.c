#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *sub_str;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		start = 0;
		len = 0;
	}
	sub_str = (char *)malloc(len + 1);
	if (!sub_str)
		return (NULL);
	ft_memcpy(sub_str, s + start, len);
	*(sub_str + len) = '\0';
	return (sub_str);
}
