#include <stdio.h>
//#include "../printf_files/head.h"


int     main(void)
{
	double f92 = 15906;
	double f91 = -5440;
	double f90 = -11373;
	double f82 = -11279;
	double f81 = 10221;
	double f80 = 15941;
	double f72 = 6142;
	double f71 = -9008;
	double f70 = -11930;
	double f62 = 1483;
	double f61 = -8828;
	double f60 = -2410;
	double f53 = -4769;
	double f52 = -3387;
	double f51 = -63;
	double f50 = 13027;
	double f40 = 15215;
	double f32 = -9466;
	double f31 = -11126;
	double f30 = 15817;
	double f21 = 1539;
	double f20 = 7514;
	double f12 = 57;
	double f11 = 11813;
	double f10 = 9356;
	double f00 = 11620;

	printf("f 11620 >+l<; = %+lf\n", f00);
	printf("f 9356; = %f\nf 11813 >+.1l<; = %+.1lf\nf 57; = %f\n", f10,f11,f12);
	printf("f 7514 ><; = %f\nf 1539; = %f\n", f20,f21);
	printf("f 15817 >#5L<; = %#5Lf\nf -11126; = %f\nf -9466 > .50l<; = % .50lf\n", f30,f31,f32);
	printf("f 15215; = %f\n", f40);
	printf("f 13027 >-.24l<; = %-.24lf\nf -63; = %f\nf -3387 ><; = %f\nf -4769; = %f\n", f50,f51,f52,f53);
	printf("f -2410 >+5.2l<; = %+5.2lf\nf -8828; = %f\nf 1483 ><; = %f\n", f60,f61,f62);
	printf("f -11930; = %f\nf -9008 >#8.9l<; = %#8.9lf\nf 6142; = %f\n", f70,f71,f72);
	printf("f 15941 ><; = %f\nf 10221; = %f\nf -11279 > 5.38l<; = % 5.38lf\n", f80,f81,f82);
	printf("f -11373; = %f\nf -5440 >-3.8L<; = %-3.8Lf\nf 15906; = %f\n", f90,f91,f92);
	return (0);
}
