#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t len)
{
	size_t	src_len;

	if (dst == 0 || src == 0)
		return (0);
	src_len = ft_strlen(src);
	if (src_len + 1 < len)
		ft_memcpy(dst, src, src_len + 1);
	else if (len != 0)
	{
		ft_memcpy(dst, src, len - 1);
		dst[len - 1] = '\0';
	}
	return (src_len);
}
