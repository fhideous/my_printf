#include "libft.h"

void					*ft_memccpy(void *dst, const void *src,
	int c, size_t len)
{
	unsigned char		*ptr;
	const unsigned char *src_ptr;

	ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
	while (len--)
	{
		*ptr = *src_ptr;
		if (*src_ptr == (unsigned char)c)
			return (++ptr);
		ptr++;
		src_ptr++;
	}
	return (NULL);
}
