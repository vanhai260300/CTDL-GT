#include<stdio.h>
#include<math.h>
float TTSQRT7(int n)
{
	
	if (n==1)
		return 1.0;
	else
		return sqrt(2+TTSQRT7(n-1));
}
main()
{
	int x;
	printf("Nhap x: ");
	scanf("%d",&x);
	printf("A=%f\n",TTSQRT7(x));
}
