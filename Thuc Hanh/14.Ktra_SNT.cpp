#include<stdio.h>
#include<math.h>
int SNT(int n)
{
		if (n<2)
			return 0;
		if (n==2)
			return 1;
		else
			for (int i=2;i<=sqrt(n);i++)
			{
				if  (SNT(i) && n%i == 0)
				return 0;
			}
			return 1;
}
main()
{
	int x;
	printf("Nhap x: ");
	scanf("%d",&x);
	if (SNT(x)==1)
		printf("SNT");
	else
		printf("Khong");
}
