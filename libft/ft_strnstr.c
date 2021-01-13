#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i_hay;
	size_t i_ne;

	i_hay = 0;
	i_ne = 0;
	if (!*needle)
		return ((char *)haystack);
	while (*(haystack + i_hay) && i_hay < len)
	{
		if (*(haystack + i_hay) == *needle)
		{
			while (*(needle + i_ne) &&
					*(haystack + i_hay + i_ne) == *(needle + i_ne) &&
					len > i_ne + i_hay)
			{
				i_ne++;
				if (*(needle + i_ne) == '\0')
					return ((char *)(haystack + i_hay));
			}
		}
		i_hay++;
	}
	return (NULL);
}
