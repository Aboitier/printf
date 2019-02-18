#include <stdio.h>
#include "../files/includes/head.h"


int	main (void)
{
	int d09 = 1985;
	int d08 = 8182;
	int d07 = -12670;
	int d06 = 9596;
	int d05 = -12103;
	int d04 = 8953;
	int d03 = 7832;
	int d02 = -6270;
	int d01 = -3931;
	int d00 = 8658;

	ft_printf("d 8658 >h<; = %hd\nd -3931; = %d\nd -6270 >+13.7ll<; = %+13.7lld\nd 7832; = %d\nd 8953 ><; = %d\nd -12103; = %d\nd 9596 >+9.2h<; = %+9.2hd\nd -12670; = %d\nd 8182 >#2.8<; = %#2.8d\nd 1985; = %d\n", d00,d01,d02,d03,d04,d05,d06,d07,d08,d09);
	return (0);
}
