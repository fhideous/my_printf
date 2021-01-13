#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*conc_str;
	size_t	s1_len;
	size_t	s2_len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	conc_str = (char *)malloc(s1_len + s2_len + 1);
	if (!conc_str)
		return (NULL);
	ft_memcpy(conc_str, s1, s1_len);
	ft_memcpy(conc_str + s1_len, s2, s2_len);
	*(conc_str + s1_len + s2_len) = '\0';
	return (conc_str);
}
