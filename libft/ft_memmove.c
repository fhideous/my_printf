#include "libft.h"

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*ptr;
	const unsigned char	*src_ptr;

	if (dst == NULL && src == NULL)
		return (NULL);
	ptr = (unsigned char*)dst;
	src_ptr = (unsigned char*)src;
	if (src_ptr < ptr)
		while (len--)
			*(ptr + len) = *(src_ptr + len);
	else
		while (len--)
			*ptr++ = *src_ptr++;
	return (dst);
}
