#include "libft.h"
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	if (fd)
		write(fd, &c, sizeof(c));
}
