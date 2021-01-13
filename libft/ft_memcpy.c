#include "libft.h"

void			*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char		*ptr;
	const unsigned char	*src_ptr;

	if (dst == NULL && src == NULL)
		return (0);
	ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
	while (len--)
		*ptr++ = *src_ptr++;
	return (dst);
}
