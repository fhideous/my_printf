#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "headers/ft_printf.h"

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define  BUFF_SIZE 100000

void var(char *format, ...)
{
	va_list ap;
	va_start(ap, format);
	if(!strcmp(format, "%d"))
	{
		int x;
		while ((x = va_arg(ap, int)))
			printf ("You passed decimal object with value %d\n", x);
	}

	if(!strcmp(format, "%s"))
	{
		char *p;
		while ((p = va_arg(ap, char*)))
			printf ("You passed c-string \"%s\"\n", p);
	}
	va_end (ap);
}

void check_my (int arg, char *strs[], int len)
{

	int j = 0;
	ft_printf("==================================");
	ft_printf("\n=======       %-11d=========\n",arg);
	ft_printf("==================================\n");
	while (j < len)
	{
	//	ft_printf("\nmy:\n");
		ft_printf("%s:\t", strs[j]);
		int i =  ft_printf (strs[j], arg);
		ft_printf("\t return: %d\n", i);
		//*strs++;
		j++;
	//	printf ("%s", *strs);
	}
}

void check_orig (int arg, char **strs, int len)
{
	int j = 0;
	printf("==================================");
	printf("\n=======       %-11d=========\n",arg);
	printf("==================================\n");
	while (j < len)
	{
	//	printf("\noriginal:\n");
		printf("%s:\t", strs[j]);
		int i = printf (strs[j], arg);
		printf("\t return: %d\n", i);
		j++;

	}
}

void check_un_my (unsigned int arg, char *strs[], int len)
{

	int j = 0;
	ft_printf("==================================");
	ft_printf("\n=======       %-11u=========\n",arg);
	ft_printf("==================================\n");
	while (j < len)
	{
		//	ft_printf("\nmy:\n");
		ft_printf("%s:\t", strs[j]);
		int i =  ft_printf (strs[j], arg);
		ft_printf("\t return: %d\n", i);
		//*strs++;
		j++;
		//	printf ("%s", *strs);
	}
}

void check_un_orig (unsigned int arg, char **strs, int len)
{
	int j = 0;
	printf("==================================");
	printf("\n=======       %-11u=========\n",arg);
	printf("==================================\n");
	while (j < len)
	{
		//	printf("\noriginal:\n");
		printf("%s:\t", strs[j]);
		int i = printf (strs[j], arg);
		printf("\t return: %d\n", i);
		j++;
	}
}


void check_my_str (char* arg, char *strs[], int len)
{

	int j = 0;
	ft_printf("==================================");
	ft_printf("\n=======       %-11s=========\n",arg);
	ft_printf("==================================\n");
	while (j < len)
	{
		//	ft_printf("\nmy:\n");
		ft_printf("%s:\t", strs[j]);
		int i =  ft_printf (strs[j], arg);
		ft_printf("\t return: %d\n", i);
		//*strs++;
		j++;
		//	printf ("%s", *strs);
	}
}

void check_orig_str (char* arg, char **strs, int len)
{
	int j = 0;
	printf("==================================");
	printf("\n=======       %-11s=========\n",arg);
	printf("==================================\n");
	while (j < len)
	{
		//	printf("\noriginal:\n");
		printf("%s:\t", strs[j]);
		int i = printf (strs[j], arg);
		printf("\t return: %d\n", i);
		j++;

	}
}

void check_my_char (int arg, char **strs, int len)
{

	int j = 0;
	ft_printf("==================================");
	ft_printf("\n=======       %-11c=========\n",arg);
	ft_printf("==================================\n");
	while (j < len)
	{
		//	ft_printf("\nmy:\n");
		ft_printf("%s:\t", strs[j]);
		int i =  ft_printf (strs[j], arg);
		ft_printf("\t return: %d\n", i);
		//*strs++;
		j++;
		//	printf ("%s", *strs);
	}
}

void check_orig_char (int arg, char **strs, int len)
{
	int j = 0;
	printf("==================================");
	printf("\n=======       %-11c=========\n",arg);
	printf("==================================\n");
	while (j < len)
	{
		//	printf("\noriginal:\n");
		printf("%s:\t", strs[j]);
		int i = printf (strs[j], (char)arg);
		printf("\t return: %d\n", i);
		j++;

	}
}



void check_my_ptr (void *arg, char **strs, int len)
{

	int j = 0;
	ft_printf("==================================");
	ft_printf("\n=======       %-14p=====\n",arg);
	ft_printf("==================================\n");
	while (j < len)
	{
		//	ft_printf("\nmy:\n");
		ft_printf("%s:\t", strs[j]);
		int i =  ft_printf (strs[j], arg);
		ft_printf("\t return: %d\n", i);
		//*strs++;
		j++;
		//	printf ("%s", *strs);
	}
}

void check_orig_ptr (void *arg, char **strs, int len)
{
	int j = 0;
	printf("==================================");
	printf("\n=======       %-14p=====\n",arg);
	printf("==================================\n");
	while (j < len)
	{
		//	printf("\noriginal:\n");
		printf("%s:\t", strs[j]);
		int i = printf (strs[j], arg);
		printf("\t return: %d\n", i);
		j++;

	}
}


char** line_for_check(char **line, int type, int line_len)
{
	char **str = calloc (line_len, sizeof(char*));
	int i = -1;
	char *str_add;
	str_add = calloc(3, sizeof(char));
	str_add[0] = (char)type;
	str_add[1] = '\0';
	while (++i < line_len)
		str[i] = ft_strjoin(line[i], str_add);
	free(str_add);
	return (str);
}




//unsigned int take_address(int a)
//{
//	unsigned int *b;
//
//	b = &a;
//	return (b)
//}

int main(void)
{
	int i;
//	i = 0;
	//int j[] = {-123456, -99, -10, -1, 0, 1, 10, 99, 123456};
	int a[] = {-214748368, -9876543, -357, -10, -1, 0,
			 1, 10, 357, 9251112, 2147483647};
	int a1[] = {-3};
	char *check[] = {
			"%","%-", "%5", "%0", "%12", "%1",
			"%.0", "%.3", "%.1", "%.12", "%0.0",
			"%0.1", "%1.0", "%1.1",
			"%-0", "%-0.0", "%-0.12", "%-12.0",
			"%-.12", "%-14", "%-.1", "%.0",
			"%-3", "%-6.4", "%4.5", "%02.1", "%012.2", "%-012.2",
			"%-4", "%1.4", "%0.5", "%1.16", "%.16",
			"%3.5", "%5.3", "%0.2", "%02", "%09","%02.4",
			"%04.2", "%04.4", "%00", "%00.0",
			"%.1", "%00",
			"%-.0", "%-0.0", "-12.0", "%00.0", "%09",
			"%-09.5", "%-9.0", "%04",
			"%9",	"%09","%01", "%04", "%00", "%-9", "%-.9",
			"%-.0", "%-0.0" ,  "%05.9", "%09.5",
			"%-05.9", "%5.3", "%-5.3", "%-09.5", "%-9.5", "%-05.9",
			"%00.0", "%5.3", "%0.2", "%02", "%3.0", "%05.5", "%0.10", "%.10"
	};
	char *check54[] = {"%1.0"};

	int a_len = sizeof(a) / sizeof(a[0]);
	int len_check = sizeof(check) / sizeof(*check);

	char **int_check = line_for_check(check, 'd', len_check);
	char **str_check = line_for_check(check, 's', len_check);
	char **char_check = line_for_check(check, 'c', len_check);
	char **un_check = line_for_check(check, 'u', len_check);
	char **ptr_check = line_for_check(check, 'p', len_check);
//
	char *b[] = {"He", ",", "Hello ", "world ", "Hello world", "", " ", "!"};
	char *b1[] = {"!"};
	char c [] = {'a', 'b', 'c', 'd', '\t', '%', '\n'};

	char c1 [] = {'c'};
	unsigned int d[] = {0, 10, 245, 2147483647, 2147483649, 4294967295,
					 429496726, 4294967296};
	unsigned int d1[] = {0};

	unsigned int e[] = {&d[0], &a[0], &c[0], &b[4] };

	int b_len = sizeof(b) / sizeof(b[0]);
	int c_len = sizeof (c) / sizeof(c[0]);
	int d_len = sizeof (d) / sizeof(d[0]);
	int e_len = sizeof (e) / sizeof(e[0]);

//////////////				MY
//
//	printf("%p", &i);

//
//	i = -1;
//	while (++i < a_len)
//		check_my(a[i], int_check, len_check);
//
//	i = -1;
//	while (++i < b_len)
//		check_my_str(b[i], str_check, len_check);
//	i = -1;
//	while (++i < c_len)
//		check_my_char(c[i], char_check, len_check);
//	i = -1;
//	while (++i < d_len)
//		check_un_my(d[i], un_check, len_check);
	i = -1;
	while (++i < e_len)
		check_my_ptr(e[i], ptr_check, len_check);

///////////////			Original
//
//	i = -1;
//	while (++i < a_len)
//		check_orig(a[i], int_check, len_check);
//	i = -1;
//	while (++i < b_len)
//		check_orig_str(b[i], str_check, len_check);
//	i = -1;
//	while (++i < c_len)
//		check_orig_char(c[i], char_check, len_check);
//	i = -1;
//	while (++i < d_len)
//		check_un_orig(d[i], un_check, len_check);
	i = -1;
	while (++i < e_len)
		check_orig_ptr(e[i], ptr_check, len_check);
}