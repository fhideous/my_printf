#include <unistd.h>
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (fd && s)
		while (*s)
		{
			write(fd, s, sizeof(*s));
			s++;
		}
}
