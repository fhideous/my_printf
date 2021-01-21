#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "git/headers/ft_printf.h"

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define  BUFF_SIZE 100000

//void var(char *format, ...)
//{
//	va_list ap;
//	va_start(ap, format);
//	if(!strcmp(format, "%d"))
//	{
//		int x;
//		while ((x = va_arg(ap, int)))
//			printf ("You passed decimal object with value %d\n", x);
//	}
//
//	if(!strcmp(format, "%s"))
//	{
//		char *p;
//		while ((p = va_arg(ap, char*)))
//			printf ("You passed c-string \"%s\"\n", p);
//	}
//	va_end (ap);
//}
//
//void check_my (int arg, char *strs[], int len)
//{
//
//	int j = 0;
//	ft_printf("==================================");
//	ft_printf("\n=======       %-11d=========\n",arg);
//	ft_printf("==================================\n");
//	while (j < len)
//	{
//		//	ft_printf("\nmy:\n");
//		ft_printf("%s:\t", strs[j]);
//		int i =  ft_printf (strs[j], arg);
//		ft_printf("\t return: %d\n", i);
//		//*strs++;
//		j++;
//		//	printf ("%s", *strs);
//	}
//}
//
//void check_orig (int arg, char **strs, int len)
//{
//	int j = 0;
//	printf("==================================");
//	printf("\n=======       %-11d=========\n",arg);
//	printf("==================================\n");
//	while (j < len)
//	{
//		//	printf("\noriginal:\n");
//		printf("%s:\t", strs[j]);
//		int i = printf (strs[j], arg);
//		printf("\t return: %d\n", i);
//		j++;
//
//	}
//}
//
//void check_un_my (unsigned int arg, char *strs[], int len)
//{
//
//	int j = 0;
//	ft_printf("==================================");
//	ft_printf("\n=======       %-11u=========\n",arg);
//	ft_printf("==================================\n");
//	while (j < len)
//	{
//		//	ft_printf("\nmy:\n");
//		ft_printf("%s:\t", strs[j]);
//		int i =  ft_printf (strs[j], arg);
//		ft_printf("\t return: %d\n", i);
//		//*strs++;
//		j++;
//		//	printf ("%s", *strs);
//	}
//}
//
//void check_un_orig (unsigned int arg, char **strs, int len)
//{
//	int j = 0;
//	printf("==================================");
//	printf("\n=======       %-11u=========\n",arg);
//	printf("==================================\n");
//	while (j < len)
//	{
//		//	printf("\noriginal:\n");
//		printf("%s:\t", strs[j]);
//		int i = printf (strs[j], arg);
//		printf("\t return: %d\n", i);
//		j++;
//	}
//}
//
//
//void check_my_str (char* arg, char *strs[], int len)
//{
//
//	int j = 0;
//	ft_printf("==================================");
//	ft_printf("\n=======       %-11s=========\n",arg);
//	ft_printf("==================================\n");
//	while (j < len)
//	{
//		//	ft_printf("\nmy:\n");
//		ft_printf("%s:\t", strs[j]);
//		int i =  ft_printf (strs[j], arg);
//		ft_printf("\t return: %d\n", i);
//		//*strs++;
//		j++;
//		//	printf ("%s", *strs);
//	}
//}
//
//void check_orig_str (char* arg, char **strs, int len)
//{
//	int j = 0;
//	printf("==================================");
//	printf("\n=======       %-11s=========\n",arg);
//	printf("==================================\n");
//	while (j < len)
//	{
//		//	printf("\noriginal:\n");
//		printf("%s:\t", strs[j]);
//		int i = printf (strs[j], arg);
//		printf("\t return: %d\n", i);
//		j++;
//
//	}
//}
//
//void check_my_char (int arg, char **strs, int len)
//{
//
//	int j = 0;
//	ft_printf("==================================");
//	ft_printf("\n=======       %-11c=========\n",arg);
//	ft_printf("==================================\n");
//	while (j < len)
//	{
//		//	ft_printf("\nmy:\n");
//		ft_printf("%s:\t", strs[j]);
//		int i =  ft_printf (strs[j], arg);
//		ft_printf("\t return: %d\n", i);
//		//*strs++;
//		j++;
//		//	printf ("%s", *strs);
//	}
//}
//
//void check_orig_char (int arg, char **strs, int len)
//{
//	int j = 0;
//	printf("==================================");
//	printf("\n=======       %-11c=========\n",arg);
//	printf("==================================\n");
//	while (j < len)
//	{
//		//	printf("\noriginal:\n");
//		printf("%s:\t", strs[j]);
//		int i = printf (strs[j], (char)arg);
//		printf("\t return: %d\n", i);
//		j++;
//
//	}
//}
//
//
//
//void check_my_ptr (void *arg, char **strs, int len)
//{
//
//	int j = 0;
//	ft_printf("==================================");
//	ft_printf("\n=======       %-14p=====\n",arg);
//	ft_printf("==================================\n");
//	while (j < len)
//	{
//		//	ft_printf("\nmy:\n");
//		ft_printf("%s:\t", strs[j]);
//		int i =  ft_printf (strs[j], arg);
//		ft_printf("\t return: %d\n", i);
//		//*strs++;
//		j++;
//		//	printf ("%s", *strs);
//	}
//}
//
//void check_orig_ptr (void *arg, char **strs, int len)
//{
//	int j = 0;
//	printf("==================================");
//	printf("\n=======       %-14p=====\n",arg);
//	printf("==================================\n");
//	while (j < len)
//	{
//		//	printf("\noriginal:\n");
//		printf("%s:\t", strs[j]);
//		int i = printf (strs[j], arg);
//		printf("\t return: %d\n", i);
//		j++;
//
//	}
//}
//
//
//char** line_for_check(char **line, int type, int line_len)
//{
//	char **str = calloc (line_len, sizeof(char*));
//	int i = -1;
//	char *str_add;
//	str_add = calloc(3, sizeof(char));
//	str_add[0] = (char)type;
//	str_add[1] = '\0';
//	while (++i < line_len)
//		str[i] = ft_strjoin(line[i], str_add);
//	free(str_add);
//	return (str);
//}
//



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
//	int a[] = {8, -2147483648, -9876543, -357, -10, -1, 0,
//			 1, 10, 357, 9251112, 2147483647, -16};
//	int a1[] = {-3};
//	char *check[] = { "%0.",
//			"%","%-", "%-4",  "%5", "%0", "%12", "%1",
//			"%.0", "%.3", "%.1", "%.12", "%0.0",
//			"%0.1", "%1.0", "%1.1",
//			"%-0", "%-0.0", "%-0.12", "%-12.0",
//			"%-.12", "%-14", "%-.1", "%.0",
//			"%-3", "%-6.4", "%4.5", "%02.1", "%012.2", "%-012.2",
//			"%-4", "%1.4", "%0.5", "%1.16", "%.16",
//			"%3.5", "%5.3", "%0.2", "%02", "%09","%02.4",
//			"%04.2", "%04.4", "%00", "%00.0",
//			"%.1", "%00",
//			"%-.0", "%-0.0", "-12.0", "%00.0", "%09",
//			"%-09.5", "%-9.0", "%04",
//			"%9",	"%09","%01", "%04", "%00", "%-9", "%-.9",
//			"%-.0", "%-0.0" ,  "%05.9", "%09.5",
//			"%-05.9", "%5.3", "%-5.3", "%-09.5", "%-9.5", "%-05.9",
//			"%00.0", "%5.3", "%0.2", "%02", "%3.0", "%05.5", "%0.10", "%.10",
//			"%240.2", "%-42.2", "%4.240", "%0.", "%5.", "%12."
//
//	};
//	char *check54[] = {"%1.0"};
//
//	int a_len = sizeof(a) / sizeof(a[0]);
//	int len_check = sizeof(check) / sizeof(*check);
//
//	char **int_check = line_for_check(check, 'd', len_check);
//	char **str_check = line_for_check(check, 's', len_check);
//	char **char_check = line_for_check(check, 'c', len_check);
//	char **un_check = line_for_check(check, 'u', len_check);
//	char **ptr_check = line_for_check(check, 'p', len_check);
//	char **hex_check = line_for_check(check, 'x', len_check);
////
//	char *b[] = {"He", ",", "Hello ", "world ", "Hello world", "", " ", "!"};
//	char *b1[] = {"!"};
//	char c [] = {'a', 'b', 'c', 'd', '\t', '%', '\n'};
//
//	char c1 [] = {'c'};
//	unsigned int d[] = {0, 10, 245, 2147483647, 2147483649, 4294967295,
//					 429496726, 4294967296};
//	unsigned int d1[] = {0};
//
//	unsigned int e[] = {&d[0], &a[0], &c[0], &b[4] };
//
//
//	int b_len = sizeof(b) / sizeof(b[0]);
//	int c_len = sizeof (c) / sizeof(c[0]);
//	int d_len = sizeof (d) / sizeof(d[0]);
//	int e_len = sizeof (e) / sizeof(e[0]);
//

	int g = -245;
	int l = 245;
	char *str = "hello";

//	static char *s_hidden = "hi low\0don't print me lol\0";

	int r00 = 0;
	int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	g = 25;
	int		h = 4200;
	i = 8;
	int		j = -12;
	int		k = 123456789;
	l = 0;
	int		m = -12345678;

	"%0*i, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d

//	char	*n = "abcdefghijklmnop";
//	char	*o = "-a";
//	char	*p = "-12";
//	char	*q = "0";
//	char	*r = "%%";
//	char	*s = "-2147483648";
//	char	*t = "0x12345678";
//	char	*u = "-0";

//	printf("%.1i, %.1d, %.1d, %.1d, %.1d, %.1d, %.1d, %.1d\n", i, j, k, l, m,
//	c, e, d);
//	ft_printf("%.1i, %.1d, %.1d, %.1d, %.1d, %.1d, %.1d, %.1d\n\n", i, j, k, l,
//	m, c, e, d);
//	printf ("\n");
//
//
//	printf("%1.i, %1.d, %1.d, %1.d, %1.d, %1.d, %1.d, %1.d\n", i, j, k, l, m,
//	c, e, d);
//	ft_printf("%1.i, %1.d, %1.d, %1.d, %1.d, %1.d, %1.d, %1.d\n", i, j, k, l,
//	m, c, e, d);
//	printf ("\n");
//
//
//	printf("|%*i, %*d, %*d, %*d, %*d, %*d, %*d, %*d|\n", a, i, a, j, a, k, a, l,
//		   a, m, a, c, a, e, a, d);
//	ft_printf("|%*i, %*d, %*d, %*d, %*d, %*d, %*d, %*d|\n", a, i, a, j, a, k,
//			  a, l,
//			  a, m, a, c, a, e, a, d);
//	printf ("\n");
//
//	printf("%010%\n");
//	ft_printf("%010%\n");
//
//	printf("%1.p\n" ,&f);
//	ft_printf("%1.p\n" , &f);
//
//	printf("%5.p\n" ,NULL);
//	ft_printf("%5.p\n" ,NULL);
//
//	printf("|%%  %04%|\n");
//	ft_printf("|%%  %04%|\n");
//	printf ("\n");
//
//
//	printf(	"|%0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, "
//			   "%0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x,"
//			   " %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X|\n",
//			   a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k,
//			   a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c,
//			   a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e);
//	ft_printf(	"|%0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*"
//				  ".*x, "
//				  "%0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x,"
//				  " %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X|\n",
//				  a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k,
//				  a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c,
//				  a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e);
//	printf ("\n");
//
//
//	printf("|%0*.*u|\n", 4, 0, 8);
//	ft_printf("|%0*.*u|\n", 4, 0, 8);
//	printf ("\n");
//
//
//	printf("|%0*.*x|\n", 2, b, l);
//	ft_printf("|%0*.*x|\n", 2, b, l);
//	printf ("\n");
//
//
//	printf("|%0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x,"
//		   "%0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x,"
//		   " %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X|\n",
//		   a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k,
//		   a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a,
//		   b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e);
//	ft_printf("|%0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x,"
//			  "%0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x,"
//			  " %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X|\n",
//			  a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k,
//			  a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a,
//			  b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e);
//	printf ("\n");
//
//
//	printf("|%*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, "
//		   "%*.*u,"
//		   " %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X,"
//		   " %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X|\n",
//		   a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e);
//	ft_printf("|%*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, "
//			  "%*.*u,"
//			  " %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X,"
//			  " %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X|\n",
//			  a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e);
//	printf ("\n");
//
//
//	printf("|%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X|\n", i, j, k, l, m, n,
//		   c, c, j, j, j);
//	ft_printf("|%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X|\n", i, j, k, l,
//			  m, n,
//			  c, c, j, j, j);
//	printf ("\n");
//
//
//	printf("|%p|\n", NULL);
//	ft_printf("|%p|\n", NULL);
//	printf ("\n");
//
//	printf("|%4p|\n", NULL);
//	ft_printf("|%4p|\n", NULL);
//	printf ("\n");

//
//	printf(		"|%010c|\n", '\0');
//	ft_printf(		"|%010c|\n", '\0');
//	printf ("\n");
//
//	printf(		"|%c|\n", '\0');
//	ft_printf(		"|%c|\n", '\0');
//	printf ("\n");
//
//	printf(		"|%5c|\n", '\0');
//	ft_printf(		"|%5c|\n", '\0');
//	printf ("\n");
//
//	printf(		"|%-5c|\n", '\0');
//	ft_printf(		"|%-5c|\n", '\0');
//	printf ("\n");

//	printf(	"|%0d|\n", 	-2147483648);
//	ft_printf(	"|%0d|\n",	-2147483648);
//	printf ("\n");
//
//	printf(	"|%-5x|\n", 52625);
//	ft_printf(	"|%-5x|\n", 52625);
//	printf ("\n");
//
//	printf(	"|%-5x|\n", 52625);
//	ft_printf(	"|%-5x|\n", 52625);
//	printf ("\n");
//
//	printf("|%-4x|\n", 9648627);
//	ft_printf("|%-4x|\n", 9648627);
//	printf ("\n");
//
//
//	printf("|%8.3x|\n", 8375);
//	ft_printf("|%8.3x|\n", 8375);
//	printf ("\n");
//
//	printf("|%8.3x|\n", 8375);
//	ft_printf("|%8.3x|\n", 8375);
//	printf ("\n");
//
//	printf("|%0x|\n", 1);
//	ft_printf("|%0x|\n", 1);
//	printf ("\n");
//
//
//	printf("|%08x|\n", 1);
//	ft_printf("|%08x|\n", 1);
//	printf ("\n");


//
//	printf("%#x", 4294967295u);
//	ft_printf("%#x", 4294967295u);
//	printf ("\n");
//
//	printf("%*s\n", -32, "abc");
//	ft_printf("%*s\n", -32, "abc");
//	printf ("\n");
//
//	printf("%.*s\n", -3, "hello");
//	ft_printf("%.*s\n", -3, "hello");
//	printf ("\n");
//
//	printf("%-*.*s\n", 7, 3, "yolo");
//	ft_printf("%-*.*s\n", 7, 3, "yolo");
//	printf ("\n");
//
//	printf("%.*s\n", 3, "hello");
//	ft_printf("%.*s\n", 3, "hello");
//	printf ("\n");
//
//	printf("|%c\n", -0);
//	ft_printf("|%c\n", -0);
//	printf ("\n");
//
//	printf("|%c\n", 0);
//	ft_printf("|%c\n", 0);
//	printf ("\n");
//
//	printf("%% *.5i 42 == |%*.5i|\n", 4, 42);
//	ft_printf("%% *.5i 42 == |%*.5i|\n", 4, 42);
//	printf ("\n");
//
//	printf("|%-10s|\n", "HELLO!");
//	ft_printf("|%-10s|\n", "HELLO!");
//	printf ("\n");
//
//	printf("%%-*.3s LYDI == |%-*.3s|\n", 5, "LYDI");
//	ft_printf("%%-*.3s LYDI == |%-*.3s|\n", 5, "LYDI");
//	printf ("\n");
//
//	printf("Lalalala, %d%% des gens qui parlent à Ly adorent %s. Ou Presque. %p\n", 100, "Ly", &r00);
//	ft_printf("Lalalala, %d%% des gens qui parlent à Ly adorent %s. Ou Presque. %p\n", 100, "Ly", &r00);
//	printf ("\n");
//
//	printf("|%c|\n", '\n');
//	ft_printf("|%c|\n", '\n');
//	printf ("\n");
//
//	printf("%u\n", 4294967295u);
//	ft_printf("%u\n", 4294967295u);
//	printf ("\n");
//
//	printf("|%4.12i|\n", g);
//	ft_printf("|%4.12i|\n", g, 23);
//	printf ("\n");
//
//	printf("hello %s\n", "gavin");
//	ft_printf("hello %s\n", "gavin");
//	printf ("\n");
//
//
//	printf("%*s.\n", 32,"abc");
//	ft_printf("%*s.\n", 32,"abc");
//	printf ("\n");
//
//
//	printf("%5c.\n", '\x01');
//	ft_printf("%5c.\n",'\x01');
//	printf ("\n");
//
//	printf("%5c.\n", '\0');
//	ft_printf("%5c.\n",'\0');
//	printf ("\n");
//
//	printf("%3.1s.\n", NULL);
//	ft_printf("%3.1s.\n", NULL);
//	printf ("\n");
//
//	printf("%.03s.\n", NULL);
//	ft_printf("%.03s.\n", NULL);
//	printf ("\n");
//
//	printf("|%.20s.|\n", NULL);
//	ft_printf("|%.20s.|\n", NULL);
//	printf ("\n");
//
//	printf("|%.7s|\n", str);
//	ft_printf("|%.7s|\n", str);
//	printf ("\n");
//
//	printf("|%.*d|\n", -3, 12345);
//	ft_printf("|%.*d|\n", -3, 12345);
//	printf ("\n");
//
//	printf("|%4.12i|\n", g);
//	ft_printf("|%4.12i|\n", g);
//	printf ("\n");
//
//	"%.7s",
//	printf("|%.12i|\n", g);
//	ft_printf("|%.12i|\n", g);
//	printf ("\n");
//
//	printf("|%14.12i|\n", g);
//	ft_printf("|%14.12i|\n", g);
//	printf ("\n");
//
//	printf("|%.i|\n", g);
//	ft_printf("|%.i|\n", g);
//	printf ("\n");
//
//	printf("|%4.2i|\n", g);
//	ft_printf("|%4.2i|\n", g);
//	printf ("\n");
//
//	printf("|%14.2i|\n", g);
//	ft_printf("|%14.2i|\n", g);
//	printf ("\n");
//
//	printf("|%4.12i|\n", g);
//	ft_printf("|%4.12i|\n", g);
//	printf ("\n");
//


	//int	n = -4;
//	i = 8;
//printf ("|%*i|\n", n, i);
//ft_printf ("|%*i|\n", n, i);
//////////////				MY
//
//	i = -1;
//	while (++i < a_len)
//		check_my(a[i], int_check, len_check);

	i = -1;
//	while (++i < b_len)
//		check_my_str(b[i], str_check, len_check);
//	i = -1;
//	while (++i < c_len)
//		check_my_char(c[i], char_check, len_check);
//	i = -1;
//	while (++i < d_len)
//		check_un_my(d[i], un_check, len_check);
//	i = -1;
//	while (++i < e_len)
//		check_my_ptr(e[i], ptr_check, len_check);
//	i = -1;
//	while (++i < d_len)
//		check_un_my(d[i], hex_check, len_check);

///////////////			Original

	i = -1;
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
//	i = -1;
//	while (++i < e_len)
//		check_orig_ptr(e[i], ptr_check, len_check);
	i = -1;
//	while (++i < d_len)
//		check_un_orig(d[i], hex_check, len_check);

}