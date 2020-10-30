#include<stdio.h>
#include<math.h>
float TTSQRT(int n)
{
	if (n==1)
		return sqrt(1.0);
	else	
		return sqrt(n*1.0+TTSQRT(n-1));
}
main()
{
	int x;
	printf("Nhap x: ");
	scanf("%d",&x);
	printf("A=%f\n",TTSQRT(x));
}
