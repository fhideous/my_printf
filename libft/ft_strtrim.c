#include "stdlib.h"
#include "libft.h"

int		find2in1(char const *s1, char const *set, int i)
{
	int		iter;
	size_t	iter_set;

	iter = 0;
	while (s1[iter])
	{
		iter_set = 0;
		while (s1[iter] != set[iter_set] && set[iter_set])
			iter_set++;
		if (set[iter_set] == '\0')
			break ;
		iter += i;
	}
	return (iter);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len_beg_step;
	int		len_end_step;
	int		len_body;
	char	*str_trim;
	int		it;

	if (!s1)
		return (NULL);
	len_beg_step = find2in1(s1, set, 1);
	len_body = ft_strlen(s1);
	len_end_step = find2in1(s1 + len_body - 1, set, -1);
	len_body = len_body - len_beg_step + len_end_step;
	if (len_body < 0)
		len_body = 0;
	str_trim = (char *)malloc(len_body + 1);
	if (!str_trim)
		return (NULL);
	it = -1;
	while (++it < len_body)
	{
		str_trim[it] = s1[len_beg_step];
		len_beg_step++;
	}
	str_trim[it] = '\0';
	return (str_trim);
}
