#include <stdlib.h>
#include "libft.h"

static void			all_free(char **text, int len)
{
	while (len)
	{
		free(text[len]);
		len--;
	}
	free(text);
}

static	char		**str_fill(char **strs, const char *s, int len, char c)
{
	int str_len;
	int i;

	i = 0;
	while (len > 0)
	{
		str_len = 0;
		while (*s == c)
			s++;
		while ((s[str_len] != c) && (s[str_len] != '\0'))
			str_len++;
		strs[i] = ft_substr(s, 0, str_len);
		if (!strs[i])
		{
			all_free(strs, i - 1);
			return (NULL);
		}
		s += str_len;
		i++;
		len--;
	}
	return (strs);
}

static int			lenofstr(char const *s, char c)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (s[i])
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		len++;
		while (s[i] != '\0' && s[i] != c)
			i++;
		if (s[i] == '\0')
			break ;
	}
	return (len);
}

static char			**alloc_split(char const *s, char c)
{
	char	**splited;
	int		str_len;

	str_len = lenofstr(s, c);
	splited = (char **)malloc((str_len + 1) * sizeof(char*));
	if (!splited)
		return (NULL);
	splited[str_len] = NULL;
	splited = str_fill(splited, s, str_len, c);
	return (splited);
}

char				**ft_split(char const *s, char c)
{
	char **splited;

	if (!s)
		return (NULL);
	splited = alloc_split(s, c);
	return (splited);
}
