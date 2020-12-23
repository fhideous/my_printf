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

void check_orig (int arg, char *strs[], int len)
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

int main(void)
{

	int j[] = {-123456, -99, -10, -1, 0, 1, 10, 99, 123456};
	int a[] = {0,-10, 357, -357, 3, 9251112};
	char *strs[] = {"%d", "%02d", "%-5d", "%-23d",
				 "%-4.6d", "%-.14d", "%-.2d", "%.12d",
				 "%-12d", "%-3d" ,"%-6.4d", "+4.5d", " 4.5d",
				 "%+-4d", "%+-4d", "% d", "% 3d", "% .3",
				 "% 3.5d", "% 5.3d"

				 };

	int a_len = sizeof(a) / sizeof (a[0]);
	int len = sizeof(strs) / sizeof(*strs);
	char *strs_n[len];
	int i = -1;
	while (++i < len)
		strs_n[i] = ft_strjoin(strs[i], "\n");

//////////////				MY
	 i = -1;
	while (++i < a_len)
	{
		//printf ("new\n");
		check_my(a[i], strs, len);
	//	check_orig(a[i], strs);
	}

//	ft_printf("\n");
//	("%d\n", ft_printf("%032d\n", -10));
//	ft_printf( "%d\n", ft_printf("%00d\n", 10));
//	ft_printf("%d\n",ft_printf("%032d\n", -38));
/////////////			Original
//	printf("\n");
	i = -1;
	while (++i < a_len)
	{
	//	printf("new\n");
		check_orig(a[i], strs, len);

	}
//	printf(str, printf ("%d\n", 100));
//	printf("%d\n", printf("%032d\n", -10));
//	printf( "%d\n", printf("%00d\n", 10));
//	printf("%d\n", printf("%032d\n", -38));

//	printf("symbols: %d\n",printf("%032d\n", -10));

//
//	printf ("\nTest: %d\n", ++i);
//	printf("symbols: %d\n",printf("%00d\n", 10));
//	printf("my_symbols: %d\n",ft_printf("%00d\n", 10));
//
//	printf ("\nTest: %d\n", ++i);
//	printf("symbols: %d\n",printf("%00d\n", -10));
//	printf("my_symbols: %d\n",ft_printf("%00d\n", -10));
//
//	printf ("\nTest: %d\n", ++i);
//	printf("symbols: %d\n",printf("%0d\n", 10));
//	printf("my_symbols: %d\n",ft_printf("%0d\n", 10));
//
//
//	printf ("\nTest: %d\n", ++i);
//	printf("symbols: %d\n",printf("%.10d\n", -10));
//	printf("my_symbols: %d\n",ft_printf("%.10d\n", -10));
//
//	printf ("\nTest: %d\n", ++i);
//	printf("symbols: %d\n",printf("%.0d\n", 30));
//	printf("my_symbols: %d\n",ft_printf("%.0d\n", 30));
//
//	printf ("\nTest: %d\n", ++i);
//	printf("symbols: %d\n",printf("%.0d\n", 1));
//	printf("my_symbols: %d\n",ft_printf("%.0d\n", 1));
//
//	printf ("\nTest: %d\n", ++i);
//	printf("symbols: %d\n",printf("%+d\n", 124));
//	printf("my_symbols: %d\n",ft_printf("%+d\n", 124));
//
//	printf ("\nTest: %d\n", ++i);
//	printf("symbols: %d\n",printf("%+.21d\n", 124));
//	printf("my_symbols: %d\n",ft_printf("%+.21d\n", 124));
//
//	printf ("\nTest: %d\n", ++i);
//	printf("symbols: %d\n",printf("%+.2d\n", 124));
//	printf("my_symbols: %d\n",ft_printf("%+.2d\n", 124));
//
//	printf ("\nTest: %d\n", ++i);
//	printf("symbols: %d\n",printf("%+.4d\n", 124));
//	printf("my_symbols: %d\n",ft_printf("%+.4d\n", 124));
//
//	printf ("\nTest: %d\n", ++i);
//	printf("symbols: %d\n",printf("%+3d\n", 124));
//	printf("my_symbols: %d\n",ft_printf("%+3d\n", 124));
//
//	printf ("\nTest: %d\n", ++i);
//	printf("symbols: %d\n",printf("%+5d\n", 124));
//	printf("my_symbols: %d\n",ft_printf("%+5d\n", 124));
//
//	printf ("\nTest: %d\n", ++i);
//	printf("symbols: %d\n",printf("%+42.12d\n", 124));
//	printf("my_symbols: %d\n",ft_printf("%+42.12d\n", 124));
//
//	printf ("\nTest: %d\n", ++i);
//	printf("symbols: %d\n",printf("%+12.42d\n", 124));
//	printf("my_symbols: %d\n",ft_printf("%+12.42d\n", 124));
//
//	printf ("\nTest: %d\n", ++i);
//	printf("symbols: %d\n",printf("%+12.12d\n", 124));
//	printf("my_symbols: %d\n",ft_printf("%+12.12d\n", 124));
//
//	printf ("\nTest: %d\n", ++i);
//	printf("symbols: %d\n",printf("%+42.12d\n", 124));
//	printf("my_symbols: %d\n",ft_printf("%+42.12d\n", 124));
//
//	printf ("\nTest: %d\n", ++i);
//	printf("symbols: %d\n",printf("%+-d\n", 124));
//	printf("my_symbols: %d\n",ft_printf("%+-d\n", 124));
//
//	printf ("\nTest: %d\n", ++i);
//	printf("symbols: %d\n",printf("%+-.21d\n", 124));
//	printf("my_symbols: %d\n",ft_printf("%+-.21d\n", 124));
//
//	printf ("\nTest: %d\n", ++i);
//	printf("symbols: %d\n",printf("%+-.2d\n", 124));
//	printf("my_symbols: %d\n",ft_printf("%+-.2d\n", 124));
//
//	printf ("\nTest: %d\n", ++i);
//	printf("symbols: %d\n",printf("%+-.4d\n", 124));
//	printf("my_symbols: %d\n",ft_printf("%+-.4d\n", 124));
//
//	printf ("\nTest: %d\n", ++i);
//	printf("symbols: %d\n",printf("%+-3d\n", 124));
//	printf("my_symbols: %d\n",ft_printf("%+-3d\n", 124));
//
//	printf ("\nTest: %d\n", ++i);
//	printf("symbols: %d\n",printf("%+-5d\n", 124));
//	printf("my_symbols: %d\n",ft_printf("%+-5d\n", 124));
//
//	printf ("\nTest: %d\n", ++i);
//	printf("symbols: %d\n",printf("%+-42.12d\n", 124));
//	printf("my_symbols: %d\n",ft_printf("%+-42.12d\n", 124));
//
//	printf ("\nTest: %d\n", ++i);
//	printf("symbols: %d\n",printf("%+-12.42d\n", 124));
//	printf("my_symbols: %d\n",ft_printf("%+-12.42d\n", 124));
//
//	printf ("\nTest: %d\n", ++i);
//	printf("symbols: %d\n",printf("%+-12.12d\n", 124));
//	printf("my_symbols: %d\n",ft_printf("%+-12.12d\n", 124));
//
//	printf ("\nTest: %d\n", ++i);
//	printf("symbols: %d\n",printf("%+-42.12d\n", 124));
//	printf("my_symbols: %d\n",ft_printf("%+-42.12d\n", 124));
//
//	printf ("\nTest: %d\n", ++i);
//	printf("symbols: %d\n",printf("%+-42.12d\n", 124));
//	printf("my_symbols: %d\n",ft_printf("%+-42.12d\n", 124));
//



	return (1);

//	printf ("%01s \n", "");
//	printf ("%5.4d\n", -614);
//	printf ("%04d\n", -614);
//	printf ("%4 d\n", -614);
//	printf ("%4 d\n", 614);
//	printf ("%4 d\n", -614);
	//var("%d", 255, 21, 14);
	//var("%s", "test string", "af", "afw");
	return 0;
}
//
//#include <stdio.h>
//
//# define FLG_NONE	0b00000000
//# define FLG_ONE	0b00000001
//# define FLG_TWO	0b00000010
//# define FLG_THREE	0b00000100
//# define FLG_FOUR	0b00001000
//
//int main()
//{
//	unsigned char	flags;
//
//	flags = FLG_NONE;
//	if (flags & FLG_ONE)
//		printf("[-] FLG_ONE exist\n");
//	else
//		printf("[+] FLG_ONE not exist\n");
//
//	flags = flags | FLG_ONE;
//	if (flags & FLG_ONE)
//		printf("[+] FLG_ONE exist\n");
//	else
//		printf("[-] FLG_ONE not exist\n");
//
//	flags = flags | FLG_TWO;
//	if ((flags & FLG_ONE) && (flags & FLG_TWO))
//		printf("[+] FLG_ONE and FLG_TWO exist\n");
//	else
//		printf("[-] FLG_ONE or FLG_TWO not exist\n");
//
//	flags = flags & (~FLG_TWO);
//	if ((flags & FLG_ONE) && (flags & FLG_TWO))
//		printf("[-] FLG_ONE and FLG_TWO exist\n");
//	else
//		printf("[+] FLG_ONE or FLG_TWO not exist\n");
//
//	return (0);
//}