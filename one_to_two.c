#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int find_new_line(char *buf)
{
	int i = 0;
	if (!buf)
		return (0);
	while (*buf)
	{
		if (*buf == '\n')
			i++;
		buf++;
	}
	return (i);
}
void clear_line(char *buf, int len)
{
	int i = -1;
	while (++i < len)
		buf[i] = '\0';
}
size_t count_lines(const char* FNAME)
{
	char buf[50];
	int fd = open( FNAME, O_RDONLY);
	if ( fd == 0 )
	{
		return -1;
	}
	int count = 0;
	while(read(fd, buf, 50))
	{
		count += find_new_line(buf);
		clear_line(buf, 50);
	}
	return count > 0 ? count + 1 : count;
}

int to_file(const char *buf, char **new_buf, int count, int *size)
{
	int curr = 0;
	int i;
	i = 0;
	while (*(buf + i) && curr != count)
	{
		*(*new_buf + i) = buf[i];
		if( buf[i] == '\n')
			curr++;
		i++;
		(*size)++;
	}
	return (curr);
}

int find_len_remainder(char** buf, int* curr, int count)
{
	int len = 0;
	int local_curr = 0;

	while (**buf && local_curr + *curr < count)
	{
		if (**buf == '\n')
			local_curr++;
		(*buf)++;
	}
	(*curr) += local_curr;
	while (*(*buf + len) /*&& local_curr > 0*/)
	{
		//	if (*(*buf + len) == '\n')
		//		local_curr--;
		len++;
	}
	return (len);
}

int copy_half(const char *file_from, const char *file_to, int count, int flag)
{
	int start = 0;
	int curr = 0;
	if (flag == 1)
		start = count / 2;
	FILE * file = fopen( file_to, "w" );
	fclose(file);
	int from = open(file_from, O_RDONLY);
	int to = open(file_to, O_WRONLY);

	char* buf = calloc (51 , sizeof(char));
	buf[50] = '\0';
	int len_to_write = 0;
	while(curr != start)
	{
		read(from, buf, 50);
		len_to_write += find_len_remainder(&buf, &curr, start);
		write(to, buf, len_to_write * sizeof(char));
	}
//	free(buf);
	char *buf_to_file = calloc (51, sizeof(char));
	curr -= start;
	while (read(from, buf, 50) && curr - start != count / 2)
	{
		int size = 0;
		curr += to_file(buf, &buf_to_file, count / 2 - curr, &size);
		write(to, buf_to_file, size * sizeof(char));
	}
	free (buf_to_file);
	close (from);
	close (to);
	//remove(file_from);
	return (1);
}

int main(int argc, char **argv)
{

}
